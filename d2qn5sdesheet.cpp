/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Best Time to BUY and SELL STOCK

Overview:
Given an array find the pair of days to buy and sell given that the elements are the prices on the
corresponding dates. Find the maximum profit. (NOTE: BUY DATE (INDEX) < SELL DATE (INDEX)).
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Brute: Just make two for loops and find the minimum diff of buy and sell dates by updating for every
iteration.
T.C: O(n^2), S.C: O(1);

Optimal: Similar to kadane's algo, keep a minimum variable and keep it updating, and while updating,
also keep updating the max profit we can acheive with the curr val and the stored minimum.

T.C: O(n), S.C: O(1);

Extra notes:
https://www.youtube.com/watch?v=eMSfBgbiEjk&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=12
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ (leetcode)

*/

#include<bits/stdc++.h>
using namespace std;

void optimal(int arr[], int n){

	int mini = INT_MAX;
	int maxprofit = 0;

	for(int i=0;i<n;i++){
		if(arr[i]<mini){
			mini = arr[i];
		}
		int diff = arr[i]-mini;
		if(diff>maxprofit){
			maxprofit = diff;
		}
	}
	cout<<maxprofit<<endl;
}

int main(){

	//Brute is too intuitive to implement, so optimal solution is implemented.

	int n;
	cin>>n;
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	optimal(arr, n);
	
}