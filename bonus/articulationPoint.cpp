#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], vector<int> &vis, vector<int> &tm, vector<int> &low, int parent, int& timer, int node, unordered_set<int> &s){
    vis[node]++;
    low[node]=tm[node]=timer++;
    int child=0;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(adj, vis, tm, low, node,timer, node);
            if(low[it] >= tm[node] && parent!=-1){
                s.insert(node);
            }
            low[node]= min(low[node], low[it]);
            child++;
        }else if(it!=parent){
            low[node]= min(low[node], tm[it]);
        }
    }
    if(parent==-1 and child>1) s.insert(node);
}
int main() {
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
    unordered_set<int> s;
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(adj, vis, tin, low, -1, i, s); 
	    }
	}
	
	for(int i = 0;i<n;i++) {
	    if(s.find(i)!=s.end()) cout << i << endl;
	}
	
	return 0;
}