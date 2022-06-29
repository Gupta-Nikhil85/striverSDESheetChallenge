#include<bits/stdc++.h>
bool isPalin(int i, int j, string& s){
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++; j--;
    }
    return true;
}
int palindromePartitioning(string s) {
    int n = s.length();
    vector<int> dp(n+1, 0);
    for(int i=n-1; i>=0; i--){
        int cost = INT_MAX;
        for(int j=i;j<n;j++){
            if(isPalin(i, j, s)){
                int cut = 1 + dp[j+1];
                cost = min(cut, cost);
            }
        }
        dp[i]=cost;
    }
    return dp[0]-1;
}