#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    unordered_map<int, int> m;
    int ans=0;
    m[0]=1;
    int prev=0;
    for(int i=0; i<arr.size(); i++){
        prev=prev^arr[i];
        if(m.find(prev^x)!=m.end()){
            ans+=m[prev^x];
        }
        m[prev]++;
    }
    return ans;
}