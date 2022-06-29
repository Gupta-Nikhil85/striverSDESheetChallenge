#include<bits/stdc++.h>
int solve(string target, unordered_set<string>& s, unordered_map<string, int> &dp){
    int n = target.size();
    if(n==0) return 1;   
    if(dp.find(target)!=dp.end()) return dp[target];
    for(int i=1;i<n+1;i++){
        string str = target.substr(0, i);
        if(s.find(str)!=s.end() and solve(target.substr(i, n-i), s,dp)==1) return dp[target]=1;
    }
    return dp[target]=-1;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    unordered_set<string> s;
    for(auto i : arr){
        s.insert(i);
    }
    unordered_map<string, int> dp;
    int x = solve(target,s,dp);
    if(x==1) return 1;
    return 0;
}