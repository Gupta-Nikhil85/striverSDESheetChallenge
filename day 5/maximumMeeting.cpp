#include <bits/stdc++.h>


vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    vector<pair<int ,int>> v;
    for(int i=0; i<end.size(); i++){
        v.push_back(make_pair(end[i],i));
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    ans.push_back(v[0].second+1);
    int last=v[0].first;
    for(int i=1; i<v.size(); i++){
        if(start[v[i].second] > last){
            last=v[i].first;
            ans.push_back(v[i].second+1);
        }
    }
    return ans;
}