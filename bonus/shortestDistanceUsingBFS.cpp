void BFSVector(vector<int> adj[], int n, int src){
    vector<int> dist(n, 1e9);
    dist[src]=0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node= q.front();
        q.pop();
        for(auto p: adj[node]){
            if(dist[node]+1 < dist[p]){
                dist[p]=dist[node]+1;
                q.push(p);
            }
        }
    }
    for(int i=0; i<n; i++) cout<<dist[i]<<" ";
}