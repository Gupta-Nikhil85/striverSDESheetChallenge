//Memoisation

#include <bits/stdc++.h>
int f(int prev, int idx, vector<int>&rack, int n,vector<vector<int>> &dp){
    if(prev==n || idx==n) return 0;
    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
    int take=0;
    if(prev==-1 || rack[idx]>rack[prev]){
        take+=f(idx, idx+1, rack, n,dp)+ rack[idx];
    }
    int notTake= f(prev, idx+1, rack, n,dp);
    return dp[idx][prev+1]= max(take, notTake);
}

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<vector<int>> dp(n, vector<int>(n+1,-1)) ;
    return f(-1, 0, rack, n,dp);
}

//Tabulation
#include <bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(n+2,0));
    for(int idx=n-1; idx>=0; idx--){
        for(int prev=idx-1; prev>=-1; prev--){
            dp[idx][prev+1]=dp[idx+1][prev+1];
            if(prev==-1 || rack[idx]>rack[prev]){
                dp[idx][prev+1]=max(dp[idx][prev+1], dp[idx+1][idx+1]+rack[idx]);
            }
        }
    }
    return dp[0][0];    
}

//Space Optimisation
#include <bits/stdc++.h>

int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
   vector<int> dp(n,-1);
    dp[0] = rack[0];
    
    for(int i=1;i<n;i++)
    {
        int ans = rack[i];
        for(int j=0;j<i;j++)
        {
            if(rack[j]<rack[i])
            {
                ans = max(ans,rack[i]+dp[j]);
            }
        }
        dp[i] = ans;
    }
    return *max_element(dp.begin(),dp.end());   
}