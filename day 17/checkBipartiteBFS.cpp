#include <bits/stdc++.h>

bool isGraphBirpatite(vector<vector<int>> &edges) {
    vector<int> color(edges.size(),-1);
    int n=edges.size();
    vector<int>adj[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for(int i=0; i<color.size(); i++){
        if(color[i]==-1){
            queue<int> q;
            q.push(i);
            color[i]=1;
            while(!q.empty()){
                int t= q.front();
                q.pop();
                for(auto j : adj[t]){
                    if(color[j]==-1){
                        color[j]=1-color[t];
                        q.push(j);
                    }else if(color[j]==color[t]){
                        return false;
                    }
                }
            }
        }
    }
    return true;
}