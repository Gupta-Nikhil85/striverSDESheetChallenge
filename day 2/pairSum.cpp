#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    int n=arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        auto low=lower_bound(arr.begin()+i+1,arr.end(),s-arr[i]);
        auto high=upper_bound(arr.begin()+i+1,arr.end(),s-arr[i]);
        for(int j=0; j<high-low; j++){
            ans.push_back({arr[i],s-arr[i]});
        }
    }
    return ans;
}