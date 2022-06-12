#include <bits/stdc++.h>

bool canAllocate(vector<int> &time, int m, long long mx, int n){
    long long day=1;
    long long sum=0;
    for(int i=0; i<m;i++){
        if(time[i]>mx) return false;
        if(sum+time[i]>mx) {
            day++;
            sum=time[i];
        } else{
            sum+=time[i];
        }
    }
    return (day<=n);
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
    long long low=INT_MAX;
    long long high=0;
    for(int i=0; i<m; i++){
        high+=time[i];
        low=min(low, (long long ) time[i]);
    }
    long long ans=high;
    while(low<=high){
        long long mid= (high+low)>>1;
        if(canAllocate(time, m, mid,n)){
            ans=min(ans, mid);
            high=mid-1;
        }else low=mid+1;
    }
    return ans;
}