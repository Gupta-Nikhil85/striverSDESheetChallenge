#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> permutation, int n)
{
    //  Write your code here.
    int idx=n;
    for(int i=n-1; i>0;i--){
        if(permutation[i-1] < permutation[i]){
            idx=i;
            break;
        }
    }
    if(idx==n){
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    int tbs=idx;
    for(int i=idx; i<n; i++){
        if(permutation[i] > permutation[idx-1]){
            tbs=i;
        }
    }
    swap(permutation[tbs], permutation[idx-1]);
    reverse(permutation.begin()+idx, permutation.end());
    return permutation;
    
}