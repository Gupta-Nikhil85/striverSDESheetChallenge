#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<pair<int,int>> adj[vertices]; //Node, dis between
    for(int i=0;i<edges;i++)
    {
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int> dis(vertices, INT_MAX);
    dis[source]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, 
    greater<pair<int,int>>> q; //dis, node
    q.push({0,source});
    
    while(!q.empty()){
        pair<int,int> node= q.top();
        q.pop();
        for(auto p : adj[node.second]){
            if(p.second+ node.first < dis[p.first]){
                dis[p.first]= p.second+ node.first;
                q.push({dis[p.first], p.first});
            }
        }
    }
    return dis;
    
}
