/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Inversion of Array (Using Merge Sort) 

Overview: Given an array find the number of count inversions in the array. Count inversion can be 
defined as the follows: no of instances when i>j and arr[i]>arr[j].

Brute: for(for()) loop and find the number of times this case satisfies.
T.C: O(n^2), S.C: O(1);

Optimal: Here we use a kind of merge sort, which is modified for this specific purpose of the qn.
In general the merge sort breaks the array into individual elements and compare them in the
individual level and the merge them back according to the comparision. So this is also similar
but after breaking into the individual elements before combining them, we count the number of elements
to the right of the smaller element and add them to the inversion count variable, in each iteration of 
merge process.
T.C: O(nlogn), S.C: O(n);

Extra notes: https://www.youtube.com/watch?v=kQ1mJlwW-c0&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=11

*/

#include<bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int start, int mid, int end) {
    int n1 = mid - start + 1; // mid is included
    int n2 = end - mid;
    // create 2 arrays for the left and right part
    int left[n1], right[n2];
    for(int i = 0; i < n1; i++)
        left[i] = arr[start + i];
    for(int i = 0; i < n2; i++)
        right[i] = arr[mid + i + 1];
    // 3 pointers
    int i = 0, j = 0, k = start;
    int count = 0;
    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else {
            // count inversions
            count += (n1 - i);
            arr[k++] = right[j++];
        }
    }
    // add the remaining elements
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];
    
    return count;
}

int inversionfunc(vector<int> &arr, int start, int end){
	if(start >= end){
        return 0;
	}
    
    // recursivec calls: merge sort
    int result = 0, mid = start + (end - start) / 2;
    result += inversionfunc(arr, start, mid);
    result += inversionfunc(arr, mid + 1, end);
    // cross-inversions
    result += merge(arr, start, mid, end);

    return result;
}

void optimal(vector<int> &arr, int n){
	int ans = inversionfunc(arr, 0, n-1);
	cout<<ans<<endl;
}

int main(){

	//brute method was not coded cause it is too intuitive, optimal method's code is implemented

	int n;
	cin>>n;
	vector<int> arr;
	
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		arr.push_back(x);
	}

	optimal(arr, n);
	
}