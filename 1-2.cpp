/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Arrays: Repeat and Missing Number 

Overview: https://www.youtube.com/watch?v=5nMGY4VUoRY&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=3

Brute: Just sort the array T.C: O(nlogn), S.C: O(1);

Better: Hashing T.C: O(n), S.C: O(n);

Optimal: sum of elements and squares of elements T.C: O(n), S.C: O(1);

Extra notes:

*/

#include<bits/stdc++.h>
using namespace std;

//Utility function
void printans(int missing, int repeating){
	
	cout<<missing<<" "<<repeating<<endl;

}

void brute(int arr[], int n){

	sort(arr, arr+n);
	int missing, repeating;

	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			repeating = arr[i];
		}
		else if((arr[i+1]-arr[i])==2){
			missing = arr[i+1]-1;
		}
	}
	if(missing==0){
		if(arr[0]!=1){
			missing = 1;
		}
		else{
			missing = n;
		}
	}

	printans(missing, repeating);

}

void better(int arr[], int n){
	std::vector<int > hashtable(n,0);
	int missing, repeating;
	for(int i=0;i<n;i++){
		++hashtable[arr[i]-1];
	}
	for(int i=0;i<n;i++){
		if(hashtable[i]==0){
			missing = i+1;
		}
		else if(hashtable[i]==2){
			repeating = i+1;
		}
	}

	printans(missing, repeating);
}

void best(int arr[], int n){

	long long int sum, sqsum, idealsum, idealsqsum;
	sum = 0;
	sqsum = 0;

	idealsum = 0;
	idealsqsum = 0;

	for(int i=0;i<n;i++){
		sum = sum+arr[i];
		sqsum = sqsum+((arr[i])*(arr[i]));
	}

	idealsum = (n*(n+1))/2;
	idealsqsum =  ((n*(n+1))*((2*n)+1))/6;

	int sumdiff = idealsum - sum;
	int sqsumdiff = idealsqsum - sqsum;

	int val1 = sqsumdiff/sumdiff;
	int val2 = val1+sumdiff;
	val2 = val2/2;

	int val3 = val2-sumdiff;

	printans(val2, val3);


}

int main(){
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	brute(arr, n);
	better(arr, n);
	best(arr, n);
}