#include <bits/stdc++.h>
//KosaRaju Algo 
//Find topo sort
//Do transpose
//Find dfs again using topo sort
//return ans


void dfs(vector<int> adj[], stack<int>&st,vector<int> &vis,int node){
    vis[node]++;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(adj, st, vis, it);
        }
    }
    st.push(node);
}

void dfsTwo(vector<int> adj[],vector<int> &vis,int node, vector<int> &temp){
    vis[node]++;
    temp.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfsTwo(adj, vis, it, temp);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<int> adj[n];
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
    }
    vector<int> vis(n,0);    
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i])
            dfs(adj, st, vis, i);
    }
    
    //transpose graph
    vector<int>transpose[n];
    for(auto edge : edges){
        transpose[edge[1]].push_back(edge[0]);
    }
    for(int i=0; i<n; i++) vis[i]=0;
    
    vector<vector<int>>  ans;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            vector<int> temp;
            dfsTwo(transpose, vis ,node, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}