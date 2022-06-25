int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n+1, vector<int>(n+1,1e9));
    for(auto edge: edges){
        adj[edge[0]][edge[1]]=edge[2];
    }
    for(int i=0;i<=n; i++){
        adj[i][i]=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(j==k) adj[j][k]=0;
                else if(j==i || k==i) adj[j][k]=adj[j][k];
                else if(adj[j][i]!=1e9 && adj[i][k]!=1e9 && 
                       adj[j][k]> adj[j][i]+ adj[i][k]){
                        adj[j][k]=adj[j][i]+ adj[i][k];
                }
            }
        }
    }
    return adj[src][dest];
}