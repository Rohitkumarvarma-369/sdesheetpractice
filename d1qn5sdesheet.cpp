/*

Rohit Kumar Varma (@immortal_1 at codechef and codeforces)
Amrita Vishwa Vidyapeetham, Amritapuri

Title: Merge Intervals

Overview: given a collection of intervals like [[1,3], [2,6], [8, 10], [15, 18]], merge the overlapping
intervals, O/P: [[1, 6], [8, 10], [15, 18]]

** In interview we need to ask if the array is sorted or not.
If not sorted we sort the array.

Brute: We traverse throught the sorted array and check if the the current pair of intervals exisist in the
extra ds if it exisits we skip else we search for merging interval after the pair if exisits it merges
and stores it in the extra ds, else stores the pair itslef in the extra ds
T.C: O(nlogn)+O(n^2), S.C: O(n);

Optimal: First sort the vector intervals. Maintain a pair<int, int> and intialize it as first pair in the interval vector, and iterate
linearly through the interval array and check if the current pair merges with the pair variable we are
maintaining, if it merges replace the variable with the merged pair, and continue till we find non merging
pair, if found push the current value of the variable into a data structure and then replace the curr var
with the non merging pair of the interval, finally we get all the merging pairs of the interval into the 
data structure.
T.C: O(nlogn)+O(n), S.C: O(n);


Extra notes: https://www.youtube.com/watch?v=2JzRBPFYbKE&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7

*/

#include<bits/stdc++.h>
using namespace std;

bool checkmerge(pair<int, int>temppair, pair<int, int>curr){
	if(temppair.second>=curr.first){
		return true;
	}
	else{
		return false;
	}
}

pair<int, int> merge(pair<int, int>temppair, pair<int, int>curr){
	pair<int, int> mergedpair;
	mergedpair.first = temppair.first;
	if(curr.second>temppair.second){
		mergedpair.second = curr.second;
	}
	else{
		mergedpair.second = temppair.second;
	}
	return mergedpair;
}

void brute(vector<pair<int, int>> intervals, int n){
	vector<pair<int, int>> merged;

	for(int i=0;i<n;i++){
		pair<int, int> temppair;
		temppair.first = intervals[i].first;
		temppair.second = intervals[i].second;
		if(merged.size()==0){
			for(int j=i+1;j<n;j++){
				pair<int, int> curr;
				curr.first = intervals[j].first;
				curr.second = intervals[j].second;
				bool ismerging = checkmerge(temppair, curr);
				if(ismerging){
					pair<int, int> final = merge(temppair, curr);
					merged.push_back(final);
				}
				if(ismerging==true){
					j = n+1;
				}
			}
		}
		else{
			bool ismerging = checkmerge(merged[merged.size()-1],temppair);
			if(ismerging==true){
				continue;
			}
			else{
				for(int j=i+1;j<n;j++){
					pair<int, int> curr;
					curr.first = intervals[j].first;
					curr.second = intervals[j].second;
					ismerging = checkmerge(temppair, curr);
					if(ismerging){
						pair<int, int> final = merge(temppair, curr);
						merged.push_back(final);
						break;
					}
				}
				if(ismerging==false){
					merged.push_back(temppair);
				}
			}
		}


	}
	for(int i=0;i<merged.size();i++){
		cout<<merged[i].first<<" "<<merged[i].second<<endl;
	}
}

void optimal(vector<pair<int, int>> intervals, int n){
	pair<int, int> curr;
	curr.first = intervals[0].first;
	curr.second = intervals[0].second;

	vector<pair<int, int>> mergedvector;

	for(int i=0;i<n;i++){
		bool checkbool = checkmerge(curr, intervals[i]);
		if(checkbool){
			curr = merge(curr, intervals[i]);
		}
		else{
			mergedvector.push_back(curr);
			curr.first = intervals[i].first;
			curr.second = intervals[i].second;
		}
	}
	mergedvector.push_back(curr);
	for(int i=0;i<mergedvector.size();i++){
		cout<<mergedvector[i].first<<" "<<mergedvector[i].second<<endl;
	}
}

int main(){

	int n;
	cin>>n;

	vector<pair<int, int>> intervals;

	for(int i=0;i<n;i++){
		int firstvar, secondvar;
		cin>>firstvar>>secondvar;
		pair<int, int> temppair;
		temppair.first = firstvar;
		temppair.second = secondvar;

		intervals.push_back(temppair);
	}

	brute(intervals, n);
	optimal(intervals, n);
	
}