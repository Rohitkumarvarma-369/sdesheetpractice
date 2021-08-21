/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Set Matrix Zeros 

Overview: Given an matrix, with zerores at certian positions, if a postion contains zero, make that col
row filled with zeroes. 

Brute: We can iterate through the whole array and when we find 0 we traverse its whole row and coloumn and
if the element is not 0 than we change the element to -1, after changing all the required elements to -1
we traverse again and make all -1's 0/
T.C: O((n*m)*(n+m)), S.C: O(1);

Better: We take two dummy arrays, we traverse throgught the array and if we find the elemnt to be zero
then we make the col index and row index in the dummy arrays zero and again traverse the matrix, if
one of the col or row at current index is zero we change the curr element to zero.
T.C: O((n*m)+(n*m)), S.C: O(n+m);

Optimal: We bring both these dummy arrays into the matrix itself and the first dummy array is the first
row, and the second dummy array is the first col, and we maintain a bool called colval = true initially
which checks if any of the element in the first col is zero, if zero we update the colval = false, this
is done to make sure that the elements dont turn zero due to the elements which turned into zeroes due to
the original zero elements. We traverse from back of the matrix and fill the matrix with zeroes at 
appropirate positions according to the zeroes in the dummy arrays and the colvar.
T.C: O((n*m)+(n*m)), S.C: O(1);

Extra notes:

*/

#include<bits/stdc++.h>
using namespace std;

void optimal(vector<vector<int>> matrix, int rows, int cols){
	bool colvar = true;
	for(int i=0;i<rows;i++){
		if(matrix[i][0]==0){
			colvar = false;
		}
		for(int j=1;j<cols;j++){
			if(matrix[i][j]==0){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for(int i=rows-1;i>=0;--i){
		for(int j = cols-1;j>=1;--j){
			if(matrix[i][0]==0 || matrix[0][j] ==0){
				matrix[i][j] = 0;
			}
		}
		if(colvar ==false){
			matrix[i][0] = 0;
		}
	}

	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main(){

	int n, m;
	cin>>n>>m;

	vector<vector<int>> matrix;
	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<m;j++){
			int x;
			cin>>x;
			temp.push_back(x);
		}
		matrix.push_back(temp);
	}

	//optimal approach only implemented because brute and better are too intuitive
	optimal(matrix, n, m);

	
}