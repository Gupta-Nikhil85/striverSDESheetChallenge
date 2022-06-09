#include <bits/stdc++.h>
bool comp(pair<int, int>p1, pair<int, int> p2){
    return p1.second/(double)p1.first > p2.second/(double) p2.first;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);
    double ans=0.0;
    for(int i=0; i<n; i++){
        if(w==0) return ans;
        else{
            ans+=min(w,items[i].first)*((items[i].second)/(double) items[i].first);
            w-=min(items[i].first, w);
        }
    }
    return ans;
}