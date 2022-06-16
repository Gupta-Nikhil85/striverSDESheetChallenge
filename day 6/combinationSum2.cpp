#include<bits/stdc++.h>

void f(vector<int> &arr, int idx, int target, vector<int>&cur, vector<vector<int>>&ans){
        
    if(target==0){
        ans.push_back(cur);
        return;
    }
    for(int i=idx; i<arr.size(); i++){
        if(i>idx && arr[i]==arr[i-1]){
            continue;
        }
        if(target >= arr[i]){
            cur.push_back(arr[i]);
            f(arr, i+1, target-arr[i], cur, ans);
            cur.pop_back();
        }
    }
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> cur;
    f(arr, 0, target, cur, ans);
    return ans;
}
