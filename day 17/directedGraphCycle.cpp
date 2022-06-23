#include <bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    vector<int> adj[n+1];
    vector<int> indegree(n+1);
    for(auto p : edges){
        adj[p.first].push_back(p.second);
        indegree[p.second]++;
    }
    queue<int> q;
    for(int i=1; i<n+1; i++){
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int node= q.front();
        for(auto i : adj[node]){
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
        q.pop();
        cnt++;
    }
    if(cnt==n) return false;
    return true;
}