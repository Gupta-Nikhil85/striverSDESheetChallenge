#include <bits/stdc++.h>

int findpar(int node, vector<int> &parent){
    if(parent[node]==node) return node;
    return parent[node]=findpar(parent[node],parent);
}

void uniontemp(vector<int> &parent, vector<int> &rank, int u, int v){
    u=findpar(u,parent);
    v=findpar(v,parent);
    if(rank[u] > rank[v]){
        parent[v]=u;
    }else if(rank[v]> rank[u]){
        parent[u]=v;
    }else{
        parent[v]=u;
        rank[u]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &graph) {
    vector<int> parent(n+1), rank(n+1,0);
    for(int i=1; i<=n; i++){
        parent[i]=i;
    }
    vector<pair<int, pair<int,int>>> v;
    for(auto p : graph){
        v.push_back(make_pair(p[2],make_pair(p[0],p[1])));
    }
    sort(v.begin(), v.end());
    int ans=0;
    for(auto i : v){
        if(findpar(i.second.first, parent)!=findpar(i.second.second, parent)){
            uniontemp(parent, rank, i.second.first, i.second.second);
            ans+=i.first;
        }
    }
    return ans;   
}