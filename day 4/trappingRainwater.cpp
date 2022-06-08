#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    long left[n],right[n];
    left[0]=arr[0];
    right[n-1]=arr[n-1];
    for(int i=1; i<n; i++){
        left[i]=max(left[i-1],arr[i]);
        right[n-i-1]= max(arr[n-i-1], right[n-i]);
    }
    long ans=0;
    for(int i=0; i<n; i++){
        ans+=min(left[i],right[i])-arr[i];
    }
    return ans;    
}