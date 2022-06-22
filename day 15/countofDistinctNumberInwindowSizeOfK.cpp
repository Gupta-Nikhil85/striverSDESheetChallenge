#include <bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    int n=arr.size();
    unordered_map<int,int> m;
    vector<int> ans;
    for(int i=0; i<k; i++){
        m[arr[i]]++;
    }
    ans.push_back(m.size());
    for(int i=k; i<n; i++){
        m[arr[i-k]]--;
        m[arr[i]]++;
        if(m[arr[i-k]]==0) m.erase(arr[i-k]);
        ans.push_back(m.size());
    }
    return ans;
}
