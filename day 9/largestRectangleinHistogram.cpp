#include <bits/stdc++.h>

int largestRectangle(vector < int > & heights) {
    int n=heights.size();
     vector<int> left(n,-1), right(n,n);
     stack<int> l,r;
     l.push(0);
     r.push(n-1);
    for(int i=1; i<n; i++){
        while(!l.empty() && heights[l.top()] >= heights[i]){
            l.pop();
        }
        if(!l.empty()) left[i]=l.top();
        l.push(i);
    }
    for(int i=n-2; i>=0; i--){
        while(!r.empty() && heights[r.top()] >= heights[i]){
            r.pop();
        }
        if(!r.empty()) right[i]=r.top();
        r.push(i);
    }
    int ans=0;
    for(int i=0; i<n; i++){
        ans=max(ans, (right[i]-left[i]-1)*heights[i]);
    }
    return ans;
}