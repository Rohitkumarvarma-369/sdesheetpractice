/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

//Dutch National Flag alogirthm (similar)
QN: Sort an array of 0’s 1’s 2’s without using extra space or sorting algo LINK: https://leetcode.com/problems/sort-colors/

Bruteforce: Just sort : Time complexity: O(nlogn), Space complexity: O(1);
Better: Count sort: Time complexity: O(2n)
Optimal: Dutch national falf algorithm (low-mid-high): Time complexity: O(n), Space complexity: O(1)

*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void bruteforcesoln(int arr[], int n){

	sort(arr,arr+n);

	cout<<"Bruteforce solution: ";

	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void bettersoln(int arr[], int n){
	int countzeroes, countones, counttwos;
	countzeroes = 0;
	countones = 0;
	counttwos = 0;

	for(int i=0;i<n;i++){
		if(arr[i]==0){
			++countzeroes;
		}
		else if(arr[i]==1){
			++countones;
		}
		else{
			++counttwos;
		}
	}

	int ansarr[n];

	for(int i=0;i<n;i++){
		if(countzeroes!=0){
			ansarr[i] = 0;
			--countzeroes;
		}
		else if(countones!=0){
			ansarr[i] = 1;
			--countones;
		}
		else{

			ansarr[i] = 2;
			--counttwos;

		}
	}

	cout<<"Better solution: ";

	for(int i=0;i<n;i++){
		cout<<ansarr[i]<<" ";
	}
	cout<<endl;
}

void bestsoln(int arr[], int n){
	int low = 0;
	int high = n-1;
	int mid = 0;

	while(mid<=high){//condition till which the algo continues
		if(arr[mid]==0){//check when 0

			int temp1 = arr[low];
			arr[low] = arr[mid];
			arr[mid] = temp1;
			++low;
			++mid;
			continue;

		}
		else if(arr[mid]==1){//check when 1

			++mid;
			continue;

		}
		else{//check when 2
			int temp2 = arr[high];
			arr[high] = arr[mid];
			arr[mid] = temp2;
			--high;
			continue;

		}
	}
	cout<<"Most Optimised solution: ";
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){

    	cin>>arr[i];

    }


    //bruteforce solution
    bruteforcesoln(arr,n);

    //better solution
    bettersoln(arr, n);

    //most optimised soln
    //Dutch National Flag algorithm
    bestsoln(arr,n);

	
}