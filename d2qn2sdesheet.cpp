/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Pascal Triangle 

Overview: We see 3 types of questions here 1. print the whole pascal traingle, print the nth row of a 
pascale traingle or print the mth element in nth row of a pascal traingle.

Type-1: To print the whole pascale traingle: We just use the basic condition with which pascal traingle
is built i.e. we add the top left and top right elements to get the current element.
T.C: O(n^2), S.C: O(n^2);

Type-2: To print the mth element in the nth row of a pascal traingle: We use the formula (Row-1)C(Col-1)
this takes time complexity of O(n).
T.C: O(n), S.C: O(1); 

Type-3: To print the nth row of the pascal traingle: We use the formula (Row-1)C(Col-1) itself but we 
dont directly do it for every element because doing so we need more time complexuty, i.e, O(n) for every
in the pascals traingle, that is O(n^2) to reduce that we use a trick, that is every previous element
in the row needs to be multiplied by rowno-col and divided by col, and reassign the prev val this makes
the time complexity linear time. 
T.C: O(n), S.C: O(n);

Extra notes: https://www.youtube.com/watch?v=6FLvhQjZqvM&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=8

*/
#include<bits/stdc++.h>
using namespace std;
int fact(int n);
 
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
 
// Returns factorial of n
int fact(int n)
{
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
int main(){
    int n;
    cin>>n;
    std::vector<vector<int>> pascalsTraingle(n);
    //Print all the rows of the pascals traingle
    for(int i=0;i<n;i++){
        pascalsTraingle[i].resize(i+1);
        pascalsTraingle[i][0] = pascalsTraingle[i][i] = 1;
        for(int j=1;j<i;j++){
            pascalsTraingle[i][j] = pascalsTraingle[i-1][j-1] + pascalsTraingle[i-1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<pascalsTraingle[i].size();j++){
            cout<<pascalsTraingle[i][j]<<"        ";
        }
        cout<<endl;
    }
    //Print certain row of the pascals traingle
    
    cout<<"Pascal Row to print"<<endl;
    int rowno;
    cin>>rowno;
    vector<int> pascalrow(rowno);
    if(rowno==1){
        cout<<1<<endl;
    }
    else{
        pascalrow[0] = 1;
        pascalrow[rowno-1] = 1;
        
        if(rowno>2){
            int prev = 1;
            for(int i=1;i<rowno-1;i++){
                int val = 0;
                val = prev*(rowno-(i));
                val = val/(i);
                prev = val;
                
                pascalrow[i] = val;
                
            }
            for(int i=0;i<pascalrow.size();i++){
                cout<<pascalrow[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    //Print certain element of the pascals traingle
    cout<<"Enter row of the element: "<<endl;
    int rowval;
    cin>>rowval;
    cout<<"Enter col of the element: "<<endl;
    int colval;
    cin>>colval;
    cout<<nCr(rowval-1, colval-1)<<endl;
    
}