/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Next Permutation 

Overview: Given an array of numbers print the next permuation of the array sequence

Brute: use next_permutation() inbuilt in cpp but usually inbuilt is not accepted at interview

Optimal: We find the pivot point which is the point at which the next dictionary sequence starts from
like if we take 1 2 3 the pivot point is 2 as the next number in dictionary is 1 3 2. We find this in step-1
by finding the first non-increasing number from the backside and then in step-2 we find the first number
greater than the number we find in step-1, and then we swap the numbers found in step-1 and step-2.
After swapping we reverse the numbers from pivot(step1)+1 to the last index to maintain the lowest rank
sequence.

Extra notes: https://www.youtube.com/watch?v=LuLCLgMElus&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=10

*/

#include<bits/stdc++.h>
using namespace std;

//Utility functions
void printarr(int arr[], int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void optimal(int arr[], int n){
    int i;
    // from the back, find the first element: arr[i] < arr[i + 1]
    for(i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1])
            break;
    }
    // reverse the entire sequence: 5 4 3 2 1 --> 1 2 3 4 5
    if(i < 0) {
        reverse(arr, arr+n);
        printarr(arr, n);
    }
    // from the back, find the first element: arr[j] > arr[i]
    for(int j = n - 1; j > i; j--) {
        if(arr[j] > arr[i]) {
            swap(arr[i], arr[j]);
            break;
        }
    }
    // reverse the part from i+1 till end
    reverse(arr+ i + 1, arr+n);
    printarr(arr, n);
}



int main(){

	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	optimal(arr, n);
	
}