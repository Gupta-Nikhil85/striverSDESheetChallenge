#include <bits/stdc++.h>

int f(vector<int> &arr, int i, int j, vector<vector<int>> &dp){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mn=INT_MAX;
    for(int k=i; k<j; k++){ //i->k, k+1->j
        int cur=arr[i-1]*arr[j]*arr[k] + f(arr,i,k,dp) + f(arr, k+1, j,dp);
        mn=min(mn,cur);
    }
    return dp[i][j]=mn;
}


int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int> (N,0));
    for(int i=N-1; i>=1; i--){
        for(int j=i+1; j<N; j++){
            int mn=INT_MAX;
            for(int k=i; k<j; k++){
                int cur=arr[i-1]*arr[j]*arr[k] + dp[i][k] + dp[k+1][j];
                mn=min(mn,cur);
            }
            dp[i][j]=mn;
        }
    }
    return dp[1][N-1];
}