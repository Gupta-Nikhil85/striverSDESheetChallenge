findTopo(vector<pair<int,int>> adj[], int root, stack<int>&st, vector<int> &vis){
    vis[root]=1;
    for(auto p : adj[root]){
        if(!vis[p.first]){
            findTopo(adj, p.first, st, vis);
        }
    }
    st.push(root);
}

vectorBFS(vector<pair<int,int>> adj[], int src, int n){
    vector<int> vis(n,0);
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            findTopo(adj, i, st);
        }
    }
    int dist[n];
    for(int i=0; i<n; i++){
        dist[n]=1e9;
    }
    dist[src]=0;
    while(!st.empty()){
        int node= st.top();
        if(dist[node]!=1e9){
            for(auto j : adj[node]){
                if(dist[j.first]> dist[node.first]+ j.second) dist[j.first]= dist[node.first]+ j.second;
            }
        }
    }
    for(int i=0; i<n; i++){
        (dist[i] ==1e9) ? cout<<"INF ": cout<<dist[i]<<" ";
    }
}