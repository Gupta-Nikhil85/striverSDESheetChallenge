//Recursion

int f(int *arr, int idx, int value){
    if(value==0) return 1;
    if(idx==0) return 0;
    
    int take=0;
    if(value>=arr[idx-1]){
        take=f(arr, idx, value-arr[idx-1]);
    }
    int notTake= f(arr,idx-1,value);
    return take+ notTake;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
    return f(denominations, n, value);
}

//DP:- Memoisation
#include <bits/stdc++.h>
long f(int *arr, int idx, int value, vector<vector<long>> &dp){
    if(value==0) return 1;
    if(idx==0) return 0;
    if(dp[idx][value]!=-1) return dp[idx][value];
    long take=0;
    if(value>=arr[idx-1]){
        take=f(arr, idx, value-arr[idx-1],dp);
    }
    long notTake= f(arr,idx-1,value,dp);
    return dp[idx][value]=take+ notTake;
}


long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n+1,vector<long>(value+1,-1));
    return f(denominations, n, value,dp);
}

//Tabulation

long countWaysToMakeChange(int *arr, int n, int sum)
{
    vector<vector<long>> dp(n+1,vector<long>(sum+1,0));
    for(int i=0; i<=n; i++){
        dp[i][0]=1;
    }
    for(int idx=1; idx<=n; idx++){
        for(int value=1;value<=sum; value++){
            long take=0;
            if(value>=arr[idx-1]){
                take=dp[idx][value-arr[idx-1]];
            }
            long notTake= dp[idx-1][value];
            dp[idx][value]=take+ notTake;
        }
    }
    return dp[n][sum];
}