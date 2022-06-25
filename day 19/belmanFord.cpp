int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dis(n+1,1e9);
    dis[src]=0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m; j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dis[u]+ wt < dis[v] && dis[u]!=1e9){
                dis[v]=dis[u]+wt;
            }
        }
    }
    return dis[dest];
}