#include <bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<vector<int>> adj(vertex);
    for(auto p : edges){
        adj[p.first].push_back(p.second);
        adj[p.second].push_back(p.first);
    }
    for(int i = 0; i < vertex; i++) sort(adj[i].begin(), adj[i].end());
    
    vector<bool> vis(vertex,0);
    queue<int> q;
    vector<int> ans;
    for(int i=0; i<vertex; i++){
        if(!vis[i]){
            q.push(i);
            vis[i]=true;
            while(!q.empty()){
                int t= q.front();
                q.pop();
                for(int j=0; j<adj[t].size(); j++){
                    if(!vis[adj[t][j]]) {
                        vis[adj[t][j]]=true;
                        q.push(adj[t][j]);
                    }
                }
                ans.push_back(t);
            }
        }
    }
    return ans;
}