#include <bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    queue<pair<int,int>> q;
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]==2){
                grid[i][j]=0;
                q.push(make_pair(i,j));
            }
        }
    }
    int ans=0;
    while(!q.empty()){
        int siz=q.size();
        ans++;
        for(int k=0; k<siz; k++){
            pair<int,int> p= q.front();
            int i=p.first, j=p.second;
            q.pop();
            if(i>0 && grid[i-1][j]!=0){
                grid[i-1][j]=0;
                q.push(make_pair(i-1,j));
            }
            if(j>0 && grid[i][j-1]!=0){ 
                grid[i][j-1]=0;
                q.push(make_pair(i,j-1));
            }
            if(i<n-1 && grid[i+1][j]!=0) {
                grid[i+1][j]=0;
                q.push(make_pair(i+1,j));
            }
            if(j<m-1 && grid[i][j+1]!=0){
                grid[i][j+1]=0;
                q.push(make_pair(i,j+1));
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j]!=0) return -1;
        }
    }
    return ans==0 ? 0 : ans-1;
}