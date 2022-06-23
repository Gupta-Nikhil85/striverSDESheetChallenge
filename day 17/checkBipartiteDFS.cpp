#include <bits/stdc++.h>

bool dfsCheck(vector<int> adj[], vector<int> &color, int root){
    if(color[root]==-1) color[root]=1;
    
    for(auto j : adj[root]){
        if(color[j]==-1){
            color[j]=1-color[root];
            if(!dfsCheck(adj, color, j)) return false;
        }else if(color[j]==color[root]) return false;
    }
    return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
    vector<int> color(edges.size(),-1);
    int n=edges.size();
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=0; i<n; i++){
        if(color[i]==-1){
            if(dfsCheck(adj, color, i)==false) return false;
        }
    }
    return true;
}