#include <bits/stdc++.h>

void f(int i, int n, vector<int>&arr, vector<vector<int>> &ans, 
       vector<int> curr){
    if(i==n){
        return;
    }
    for(int j=i; j<n; j++){
        curr.push_back(arr[j]);
        f(j+1,n,arr,ans,curr);
        ans.push_back(curr);
        curr.pop_back();
        while(j<n-1 && arr[j]==arr[j+1]) j++;
    }
    return;
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> curr;
    f(0,n, arr, ans,curr);
    sort(ans.begin(),ans.end());
    return ans;
    
}