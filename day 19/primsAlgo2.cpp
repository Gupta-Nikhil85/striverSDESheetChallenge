#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0;i<m;i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> parent(n+1, -1);
    vector<bool> mst(n+1, false);
    vector<int> key(n+1, INT_MAX);

    key[0] = 0;
    key[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        int node = pq.top().second;
        pq.pop();
        mst[node] = true;

        for(auto it:adj[node]){
            int next = it.first;
            int wt = it.second;
            if(mst[next]==false and wt<key[next]){
                key[next] = wt;
                parent[next] = node;
                pq.push({key[next], next});
            }

        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    return ans;
}