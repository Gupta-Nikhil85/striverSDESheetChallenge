#include <bits/stdc++.h>
void dfs(stack<int>&ans, vector<int> adj[], vector<int> &vis, int root){
    vis[root]=1;
    for(auto j : adj[root]){
        if(!vis[j]){
            dfs(ans, adj, vis, j);
        }
    }
    ans.push(root);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(int i=0; i<e; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    stack<int> ans;
    vector<int> vis(v,0);
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(ans, adj,vis, i);
        }
    }
    vector<int> topoSort;
    while(!ans.empty()){
        topoSort.push_back(ans.top());
        ans.pop();
    }
    return topoSort;
}