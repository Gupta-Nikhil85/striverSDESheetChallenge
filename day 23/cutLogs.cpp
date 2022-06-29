//Memoisation O(n*n*k)

#include <bits/stdc++.h>
int f(int n, int k, vector<vector<int>> &dp){
    if(n<=1) return n;
    if(k==1) return n;
    if(dp[n][k]!=-1) return dp[n][k];
    int cnt=INT_MAX;
    for(int t=1; t<=n; t++){
        int cur= 1+ max(f(n-t,k,dp) , f(t-1,k-1,dp));
        cnt=min(cnt,cur);
    }
    return dp[n][k]= cnt;
}

int cutLogs(int k, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    return f(n,k,dp);
}

//Memoisation O(n*k*logn)
#include <bits/stdc++.h>
int f(int n, int k, vector<vector<int>> &dp){
    if(n<=1) return n;
    if(k==1) return n;
    if(dp[n][k]!=-1) return dp[n][k];
    int cnt=INT_MAX;
    int l=1,h=n;
    while(l<=h){
        int t=(l+h)/2;
        int right=f(n-t,k,dp);
        int left=f(t-1,k-1,dp);
        if(left<right){
            l=t+1;
        }else{
            h=t-1;
        }
        int cur=1+max(left,right);
        cnt=min(cnt,cur);
    }
    return dp[n][k]= cnt;
}

int cutLogs(int k, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(k+1,-1));
    return f(n,k,dp);
}


//Tabulation
int cutLogs(int k, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(k+1,0));
    for(int i=1; i<=n; i++) dp[i][1]=i;
    
    for(int idx=1; idx<=n; idx++){
        for(int j=2; j<=k; j++){
            int cnt=INT_MAX;
            int l=1,h=idx;
            while(l<=h){
                int t=(l+h)/2;
                int right=dp[idx-t][j];
                int left=dp[t-1][j-1];
                if(left<right){
                    l=t+1;
                }else{
                    h=t-1;
                }
                int cur=1+max(left,right);
                cnt=min(cnt,cur);
            }
            dp[idx][j]= cnt;
        }
    }
    return dp[n][k];
}
