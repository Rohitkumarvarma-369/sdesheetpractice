/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Arrays: Sort an array of 0’s 1’s 2’s without using extra space or sorting algo 

Overview: https://www.youtube.com/watch?v=oaVa-9wmpns&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2

Brute: just sort the array and print it T.C: O(nlogn), S.C: O(1);

Better:  count sort T.C: O(N), S.C: O(N);

Optimal: dutch national flag algorithm T.C: O(N), S.C: O(1);

Extra notes: 

*/

#include<bits/stdc++.h>
using namespace std;

//Utilities functions
void printarray(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void brute(int arr[], int n){
	sort(arr, arr+n);
	printarray(arr,n);
}

void better(int arr[], int n){

	int countarr[3] = {0};

	for(int i=0;i<n;i++){
		if(arr[i]==0){
			++countarr[0];
		}
		else if(arr[i]==1){
			++countarr[1];
		}
		else{
			++countarr[2];
		}
	}
	int curr = 0;
	for(int i=0;i<3;i++){
		int val = countarr[i];
		int tempcurr = curr;
		for(int j = tempcurr; j<val;j++){
			arr[j] = i;
			++curr;
		}
	}
	printarray(arr,n);

}

void optimal(int arr[], int n){
	int low, mid, high;
	low = mid = 0;
	high = n-1;

	for(int i = 0;i<n;i++){
		if(arr[mid]==1){
			++mid;
			continue;
		}
		else if(arr[mid]==0){
			swap(arr[mid], arr[low]);
			++low;
			++mid;
		}
		else{
			swap(arr[mid], arr[high]);
			--high;
		}
	}

	printarray(arr,n);
}



int main(){
	
	int n;
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	brute(arr,n);//sort
	better(arr,n);//count sort
	optimal(arr,n);//dutch national flag algorithm

}
