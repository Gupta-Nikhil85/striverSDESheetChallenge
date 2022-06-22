#include <bits/stdc++.h>

bool isCycle(vector<int> &vis, vector<vector<int>> &adj, int idx, vector<vector<int>>&edges){
    queue<pair<int,int>> q;
    q.push({idx, -1});
    vis[idx]++;
    while(!q.empty()){
        int node= q.front().first;
        int pre= q.front().second;
        q.pop();
        for(auto i : adj[node]){
            if(!vis[i]){
                vis[i]++;
                q.push({i, node});
            }
            else if(pre!=i){
                return true;
            }
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> vis(n+1,0);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(isCycle(vis, adj, i, edges)) return "Yes";
        }
    }
    return "No";
}
