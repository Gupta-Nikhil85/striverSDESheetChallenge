#include <bits/stdc++.h> 
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
    for(int i=0; i<n; i++){
        arr1[m+i]=arr2[i];
    }
    int gap= (m+n+1)/2;
    while(gap>=1){
        int i=0, j=i+gap;
        while(j<n+m){
            if(arr1[i] > arr1[j]){
                swap(arr1[i], arr1[j]);
            }
            i++; j++;
        }
        if(gap==1) break;
        gap=(gap+1)/2;
    }
    return arr1;    
}