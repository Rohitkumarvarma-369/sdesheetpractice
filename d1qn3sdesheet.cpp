/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Merge two sorted Arrays without extra space 

Overview: Given two sorted arrays, merge them both in sorted order. Initially we will
try with extra space and then we will optimise without any extra space.

Brute: Use a third array and then plug in all the elements of both the arrays,
sort the third array and plug the elements back.
TL:O(nlogn), SC: O(n);

Better: We will not use any auxilary space, we will traverse the firse array and then
we will compare every element of the first array and the second array and if the elements
of the second array is greater than the first array, then swap them and place the swapped
element from the first array properly in the second array such that the sorted order remains
intact (this can be done by traversing through the second array and placing in appropirate postion)
TL:O(n), SC: O(1);

Optimal: GAP method (too complex, will implement later).

Extra notes: https://www.youtube.com/watch?v=hVl2b3bLzBw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=5


*/

#include<bits/stdc++.h>
using namespace std;

//Utility functions
void printvector(vector<int> arr){
	for(int i=0;i<arr.size();i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void brute(vector<int> one, vector<int> two, int n, int m){
	vector<int> three(n+m);
	int i,j,k;
	i = 0;
	k = 0;
	j = 0;
	while(i<n){
		three[k++] = one[i++];
	}
	while(j<m){
		three[k++] = two[j++];
	}
	sort(three.begin(), three.end());

	i = 0;
	k = 0;
	j = 0;
	while(i<n){
		one[i++] = three[k++];
	}
	while(j<m){
		two[j++] = three[k++];
	}

	printvector(one);
	printvector(two);
}

void pushsorted(vector<int> &arr, int temp){
	arr[0] = temp;
	if(arr[0]<=arr[1]){
		return;
	}
	else{

		for(int i=0;i<arr.size()-1;i++){
			if(arr[i]<=arr[i+1]){
				break;
			}
			else if(arr[i]>arr[i+1]){
				int curr = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = curr; 
			}
		}

	}
}
void optimal(vector<int> one, vector<int> two, int n, int m){

	for(int i=0;i<n;i++){
		if(one[i]<=two[0]){
			continue;
		}
		else{
			int temp;
			temp = one[i];
			one[i] = two[0];
			pushsorted(two, temp);
		}
	}

	printvector(one);
	printvector(two);
}

int main(){

	vector<int> one;
	vector<int> two;

	int n, m;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		one.push_back(x);
	}
	for(int i = 0;i<m;i++){
		int x;
		cin>>x;
		two.push_back(x);
	}

	brute(one, two, n, m);
	optimal(one, two, n, m);
	
}