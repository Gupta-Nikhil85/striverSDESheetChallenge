bool isCycleDFS(vector<bool> &vis, vector<vector<int>> &adj, int src, int prev){
    vis[src]=true;
    for(auto i : adj[src]){
        if(!vis[i]){
            if(isCycleDFS(vis, adj, i, src)) return true;
        }
        else if(i!=prev) return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adj(n+1);
    vector<bool> vis(n+1,0);
    for(int i=0; i<m; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(isCycleDFS(vis, adj, i, -1)) return "Yes";
        }
    }
    return "No";
}
