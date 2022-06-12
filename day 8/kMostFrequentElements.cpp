#include<bits/stdc++.h>

typedef pair<int,int> pi;

struct comp{
    bool operator()(pi p1, pi p2){
        return p1.second > p2.second;
    }
};

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int> m;
    for(auto a : arr){
        m[a]++;
    }
    priority_queue<pi, vector<pi>, comp> q;
    for(auto p : m){
        q.push(p);
        if(q.size()>k){
            q.pop();
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.top().first);
        q.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;    
}