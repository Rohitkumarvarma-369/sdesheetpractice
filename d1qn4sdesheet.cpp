/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Kadane's Algo (Maximum Subarray Sum)

Overview: Find the maximum sum of any subarray (consecutive elements), in the given array

Brute: three loops (0 to n-1, i to n-1, i to j here we do sum = sum+arr[k] and maxsum is calculated after this loop)
T.C: O(n^3), S.C: O(1);

Better: two loops (0 to n-1, i to n-1, and add sum at every step over here)
T.C: O(n^2), S.C: O(1);

Optimal: Kadanes algo

Extra notes: https://www.youtube.com/watch?v=w_KEocd__20&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=6

*/

#include<bits/stdc++.h>
using namespace std;

void brute(int arr[], int n){
	int maxsum = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			int sum = 0;
			for (int k = i; k <= j; ++k)
			{
				sum+= arr[k];
			}
			maxsum = max(sum, maxsum);
		}
	}
	cout<<maxsum<<endl;
}
void better(int arr[], int n){
    int maxsum = arr[0];
    if(n==1){
        cout<<arr[0]<<endl;
    }
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = i; j < n; ++j)
        {
            sum+=arr[j];
            maxsum = max(sum, maxsum);
        }
    }
    cout<<maxsum<<endl;
}

void best(int arr[], int n){
    int maxsum = arr[0];
    int currmax = 0;
    
    for(int i=0;i<n;i++){
        currmax+= arr[i];
        if(currmax>maxsum){
            maxsum=currmax;
        }

        if(currmax<0){
            currmax = 0;
        }

        
    }
    cout<<maxsum<<endl;
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