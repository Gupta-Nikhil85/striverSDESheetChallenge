#include <bits/stdc++.h>

double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    int n=a.size(), m=b.size();
    if(n>m) return median(b,a);
    int low=0, high=n;
    while(low<=high){
        int c1=(low+high)/2;
        int c2= (m+n+1)/2 -c1;
        int l1= c1>0 ? a[c1-1] : INT_MIN;
        int l2= c2>0 ? b[c2-1] : INT_MIN;
        int r1= c1<n ? a[c1] : INT_MAX;
        int r2= c2<m ? b[c2] : INT_MAX;
        if(l1<=r2 && l2<=r1){
            if((n+m)%2) return (double) max(l1,l2);
            return (max(l1,l2) + min(r1,r2))/2.0;
        }
        else if(l1>r2) high=c1-1;
        else low=c1+1;
    }
    return -1.0;
}
