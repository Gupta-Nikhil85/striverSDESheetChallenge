#include<bits/stdc++.h>
vector<vector<int>> path= {{1,0}, {0,1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}, {0,-1}, {-1,0}};

int getTotalIslands(int** arr, int n, int m)
{
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1){
                cnt++;
                queue<pair<int,int>> q;
                q.push({i,j});
                arr[i][j]=0;
                while(!q.empty()){
                    pair<int,int> p= q.front();
                    q.pop();
                    for(auto t: path){
                        int r=p.first+t[0];
                        int c=p.second+t[1];
                        if(r>=0 && c>=0 && r<n && c<m && arr[r][c]!=0){
                            q.push({r,c});
                            arr[r][c]=0;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
