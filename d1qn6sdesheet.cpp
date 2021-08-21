/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Find the duplicate in an array of N+1 integers.

Overview: Given an array and n, array elements ranging from 1 to n, find the number which is duplicate in the
array.

Brute: Sort the array and find the duplicate, but this will distort the array
T.C: O(nlogn), S.C: O(1);

Better: Hashing (Frequency array)
T.C: O(n), S.C: O(n);

Optimal: Linked List Cycle method, create a cycle of the form index->val->index and then as there are
duplicate elements of a single value, all of them point to a single index called the intersection element
we traverse through the array with fast and slow pointers(floyd cycle detection algo), and find the
intersection of fast and slow pointers and then we make the fast pointer slow and point it to the 0th index
and move both slow and fast(slowed down fast) till same elements are found and that element is the duplicate
element.
T.C: O(n), S.C: O(1);

Extra notes:
https://www.youtube.com/watch?v=32Ll35mhWg0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=2
https://www.youtube.com/watch?v=dfIqLxAf-8s (Very good explanation of the floyd cycle detection algo)
*/

#include<bits/stdc++.h>
using namespace std;

void brute(int arr[], int n){
	sort(arr, arr+n);
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			cout<<"Duplicate element: "<<arr[i]<<endl;
			break;
		}
	}
}

void better(int arr[], int n){
	int freqtable[n+1] = {0};
	for (int i = 0; i < n; ++i)
	{
		if(freqtable[arr[i]]==1){
			cout<<"Duplicate element: "<<arr[i]<<endl;
			break;
		}
		else if(freqtable[arr[i]]==0){
			++freqtable[arr[i]];
		}
	}
}

void optimal(int arr[], int n){

	if(n==0){
		cout<<"No duplicate element"<<endl;
	}
	else{
		int slow = arr[0];
		int fast = arr[0];

		do{
			slow = arr[slow];
			fast = arr[arr[fast]];
		}while(slow!=fast);

		fast = arr[0];

		while(fast!=slow){
			fast = arr[fast];
			slow = arr[slow];
		}

		cout<<"Duplicate number: "<<slow<<endl;
	}

}

int main(){

	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	better(arr, n);
	brute(arr, n);
	optimal(arr, n);
	
}