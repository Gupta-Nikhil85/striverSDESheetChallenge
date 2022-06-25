//Recursion

int f(string &str1, string &str2, int i, int j){
    if(i==0) return j;
    if(j==0) return i;
    if(str1[i-1]==str2[j-1]) return f(str1, str2, i-1, j-1);
    int del= f(str1, str2, i-1, j);
    int ins=f(str1, str2, i, j-1);
    int res=f(str1, str2, i-1, j-1);
    return min(del, min(ins, res)) +1;
}

int editDistance(string str1, string str2)
{
    int n=str1.length(), m=str2.length();
    
    return f(str1, str2,n,m);
    
}

//DP:- Memoisation
#include <vector>
int f(string &str1, string &str2, int i, int j, vector<vector<int>> &dp){
    if(i==0) return j;
    if(j==0) return i;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str1[i-1]==str2[j-1]) return dp[i][j]=f(str1, str2, i-1, j-1,dp);
    int del= f(str1, str2, i-1, j,dp);
    int ins=f(str1, str2, i, j-1,dp);
    int res=f(str1, str2, i-1, j-1,dp);
    return dp[i][j]= min(del, min(ins, res)) +1;
}

int editDistance(string str1, string str2)
{
    int n=str1.length(), m=str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    return f(str1, str2,n,m,dp);
    
}

//DP:- Tabulation
#include <vector>
int editDistance(string str1, string str2)
{
    int n=str1.length(), m=str2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i=0; i<=n; i++) dp[i][0]=i;
    for(int j=0; j<=m; j++) dp[0][j]=j;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]= min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
        }
    }
    return dp[n][m];
}
//DP:- Space Optimisation

#include <vector>
int editDistance(string str1, string str2)
{
    int n=str1.length(), m=str2.length();
    vector<int> prev(m+1,0), cur(m+1,0);
    for(int j=0; j<=m; j++) prev[j]=j;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cur[0]=i;
            if(str1[i-1]==str2[j-1]) cur[j]=prev[j-1];
            else
                cur[j]= min(prev[j-1], min(prev[j], cur[j-1]))+1;
        }
        prev=cur;
    }
    return prev[m];
}