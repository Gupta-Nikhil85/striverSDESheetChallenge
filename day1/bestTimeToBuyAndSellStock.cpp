#include <bits/stdc++.h> 
using namespace std;

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mn=INT_MAX;
    int n= prices.size();
    int ans=0;
    for(int i=0; i<n; i++){
        mn=min(prices[i], mn);
        ans=max(ans, prices[i]-mn);
    }
    return ans;
}