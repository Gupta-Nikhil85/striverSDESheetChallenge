#include <bits/stdc++.h>

int ninjaAndLadoos(vector<int> &arr1, vector<int> &arr2, int n, int m, int k) {
    // Write your code here.
    if(n>m) return  ninjaAndLadoos(arr2, arr1, m, n, k);
    int low= max(0, k-m), high =min(k,n);
    while(low<=high){
        int c1=(low+high)>>1;
        int c2= k-c1;
        int l1= c1==0 ? INT_MIN : arr1[c1-1];
        int l2= c2==0 ? INT_MIN : arr2[c2-1];
        int r1= c1==n ? INT_MAX : arr1[c1];
        int r2= c2==m ? INT_MAX : arr2[c2];
        
        if(l1<=r2 && l2<=r1) return max(l1,l2);
        else if(l1>r2) high=c1-1;
        else low=c1+1;
    }
    return 0;   
}