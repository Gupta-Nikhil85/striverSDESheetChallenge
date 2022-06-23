bool dfs(int root, vector<int> adj[], vector<bool> &vis, vector<bool> &dfsVis){
    vis[root]=1;
    dfsVis[root]=1;
    for(auto cur : adj[root]){
        if(!vis[cur]){
            if(dfs(cur, adj, vis, dfsVis)) return true;   
        }else if(dfsVis[cur]) return true;
    }
    dfsVis[root]=0;    
    return false;
}


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<bool> vis(n+1,0);
    vector<int> adj[n+1];
    for(int i=0; i<edges.size(); i++){
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<bool> dfsVis(n+1,0);
    for(int i=1;i<=n; i++){
        if(!vis[i]){
            if(dfs(i, adj,vis, dfsVis)) return 1;
        }
    }
    return 0;   
}