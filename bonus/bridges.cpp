#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> &vis, vector<int> &insertTime, vector<int>& lw, int node, vector<int> adj[], int &timer, int parent){
    vis[node]++;
    lw[node]=insertTime[node]=timer++;
    for(auto p : adj[node]){
        if(node==parent) continue;
        if(!vis[p]){
            dfs(vis, lt, lw, p, adj, timer, node);
            lw[node]= min(lw[node], lw[p]);
            if(lw[p] > insertTime[node]){
                cout<<p<<" "<<node<<endl;
            }
        }
        else{
            lw[node]= min(lw[node],insertTime[p]);
        }
    }
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
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj); 
	    }
	}
	
	return 0;
}