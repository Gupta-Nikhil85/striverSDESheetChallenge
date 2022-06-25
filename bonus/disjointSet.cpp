int parent[1e5];
int rank[1e5];
int n=1e5;

void makeSet(){
    for(int i=1; i<n; i++){
        parent[i]=i;
        rank[i]=0;
    }
}

int findPar(int node){
    if(node==parent[node]) return node;

    return parent[node]= findPar(parent[node]);
}

void union(int u, int v){
    u =findPar(u);
    v= findPar(v);
    if(rank[u] > rank[v]){
        parent[v]=u;
    }else if(rank[u]< rank[v]){
        parent[u]=v;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }
}


void main(){
    makeSet();
}