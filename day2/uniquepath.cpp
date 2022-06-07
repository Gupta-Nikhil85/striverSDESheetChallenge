#include <bits/stdc++.h> 

// int f(int m, int n,  vector<vector<int>> &dp){
//     if(m==0 && n==0) return 1;
//     if(m<0 || n<0) return 0;
//     if(dp[m][n]!=-1) return dp[m][n];
//     int right= f(m,n-1,dp);
//     int down= f(m-1,n,dp);
//     return dp[m][n]= right+ down;
// }

int uniquePaths(int m, int n) {
//     vector<vector<int>> dp(m, vector<int> (n,0));
//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(i==0 || j==0) dp[i][j]=1;
//             else{
//                 dp[i][j]=dp[i-1][j]+dp[i][j-1];
//             }
//         }
//     }
//     return dp[m-1][n-1];
    int ans=1;
    for(int i=1; i<n; i++){
        ans=(ans*(m+i-1))/i;
    }
    return ans;
}