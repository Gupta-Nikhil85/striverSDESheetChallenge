void dfs(vector<vector<int>> &adj, vector<int> &ans, vector<int> &vis, int i){
    vis[i]=1;
    ans.push_back(i);
    for(auto j : adj[i]){
        if(vis[j]==0){
            dfs(adj, ans, vis, j);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for(int i=0; i<E; i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> visited(V,0);
    vector<vector<int>> ans;
    for(int i=0; i<V; i++){
        vector<int> temp;
        if(visited[i]==0){
            dfs(adj, temp, visited, i);
        }
        if(temp.size()>0) ans.push_back(temp);
    }
    return ans;
}