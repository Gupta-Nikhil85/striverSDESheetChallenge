#include <bits/stdc++.h>

int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    sort(at, at+n);
    sort(dt, dt+n);
    int i=0, j=0;
    int ans=0, cnt=0;
    while(i<n && j<n){
        if(at[i]<=dt[j]){
            cnt++;
            ans=max(ans,cnt);
            i++;
        }else{
            j++;
            cnt--;
        }
    }
    return ans;
}