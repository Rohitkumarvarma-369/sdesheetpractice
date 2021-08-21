/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Rotate the matrix by 90 degrees

Overview: Given a matrix rotate it by 90 degrees in clockwise direction

Brute: We can use temp array and store all the rows in the main array as cols in the temp array.
T.C: O(n^2), S.C: O(n^2);

Optimal: We can transpose the array and then reverse each row in the array.
T.C: O(n^2), O(1) (in-place)

Extra notes: https://www.youtube.com/watch?v=Y72QeX0Efxw&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=13
*/

#include<bits/stdc++.h>
using namespace std;

void rotatematrix(vector<vector<int>> &matrix, int n){
	// transpose
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // reverse every row
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cout<<matrix[i][j]<<" ";
    	}
    	cout<<endl;
    }

}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> matrix;

	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			temp.push_back(x);
		}
		matrix.push_back(temp);
	}

	rotatematrix(matrix, n);
	
}