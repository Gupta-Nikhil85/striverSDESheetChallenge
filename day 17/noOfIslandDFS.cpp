#include<bits/stdc++.h>
vector<vector<int>> path= {{1,0}, {0,1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}, {0,-1}, {-1,0}};

void dfs(int **arr, int i,int j, int n,int m){
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j]==0) return;
    arr[i][j]=0;
    for(auto p: path){
        dfs(arr, i+p[0], j+p[1], n,m);
    }
    return;
}


int getTotalIslands(int** arr, int n, int m)
{
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                dfs(arr,i,j,n,m);
                cnt++;
            }
        }
    }
    return cnt;
}
