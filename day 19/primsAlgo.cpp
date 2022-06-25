#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int,int>> adj[n+1];
    for(auto p : g){
        adj[p.first.first].push_back({p.first.second, p.second});
        adj[p.first.second].push_back({p.first.first, p.second});
    }
    int parent[n+1];
    int key[n+1];
    bool mst[n+1];
    for(int i=0; i<=n; i++)
        key[i]=INT_MAX, mst[i]=false, parent[i]=-1;
    key[1]=0;
    parent[1]=-1;
    
    for(int i=1; i<n; i++){
        int mn=INT_MAX;
        int mnidx=-1;
        for(int j=1; j<=n; j++){
            if(key[j] < mn && mst[j]==false){
                mn=key[j];
                mnidx=j;
            }
        }
            mst[mnidx]=true;
            for(auto p : adj[mnidx]){
                if(!mst[p.first] && key[p.first] > p.second){
                    key[p.first] =p.second;
                    parent[p.first]= mnidx;
            }
        } 
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=n;i++){
        ans.push_back({{parent[i], i},key[i]});
    }
    return ans;
}