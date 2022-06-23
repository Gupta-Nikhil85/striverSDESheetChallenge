#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    for(auto p : edges){
        adj[p[0]].push_back(p[1]);
    }
    vector<int> ans;
    vector<int> indegree(v,0);
    for(auto p : edges){
        indegree[p[1]]++;
    }
    vector<int> vis(v+1,0);
    for(int i=0; i<v; i++){
        if(!vis[i]){
            queue<int> q;
            for(int j=0; j<v; j++){
                if(!vis[j] && indegree[j]==0){
                    vis[j]++;
                    q.push(j);
                }
            }
            while(!q.empty()){
                ans.push_back(q.front());
                int t= q.front();
                q.pop();
                for(auto p : adj[t]){
                    indegree[p]--;
                    if(!vis[p]){
                        if(indegree[p]==0){
                            q.push(p);
                            vis[p]=1;
                        }
                    }
                }
            }
        }
    }
    return ans;
}