//Recursion


int f(int arr[], int idx, int prev, int n){
    if(idx==n) return 0;
    int take=0;
    if(prev==-1 || arr[idx]>arr[prev]){
        take=1+f(arr, idx+1, idx, n);
    }
    int notTake= f(arr, idx+1, prev, n);
    return max(take, notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return f(arr, 0, -1, n);
}


//Dp :- Memoisation
#include <vector>

int f(int arr[], int idx, int prev, int n, vector<vector<int>> &dp){
    if(idx==n || prev==n) return 0;
    if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
    int take=0;
    if(prev==-1 || arr[idx]>arr[prev]){
        take=1+f(arr, idx+1, idx, n,dp);
    }
    int notTake= f(arr, idx+1, prev, n,dp);
    return dp[idx][prev+1]= max(take, notTake);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return f(arr, 0, -1, n,dp);
}

//DP :- Tabulation
#include <vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int idx=n-1; idx>=0; idx--){
        for(int prev= idx-1; prev>=-1; prev--){
            dp[idx][prev+1]=dp[idx+1][prev+1];
            if(prev==-1 || arr[idx]>arr[prev]){
                dp[idx][prev+1]=max(dp[idx][prev+1], dp[idx+1][idx+1]+1);
            }
        }
    }
    return dp[0][0];
}
//DP :- Space Optimisation
#include <vector>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> next(n+1,0), curr(n+1,0);
    for(int idx=n-1; idx>=0; idx--){
        for(int prev= idx-1; prev>=-1; prev--){
            curr[prev+1]=next[prev+1];
            if(prev==-1 || arr[idx]>arr[prev]){
                curr[prev+1]=max(next[prev+1], next[idx+1]+1);
            }
        }
        next=curr;
    }
    return next[0];
}

//Binary Search
#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp= {arr[0]};
    for(int i=1; i<n; i++){
        if(arr[i]>temp.back()){
            temp.push_back(arr[i]);
        }
        else{
            int idx= lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
            temp[idx]=arr[i];
        }
    }
    return temp.size();
}

