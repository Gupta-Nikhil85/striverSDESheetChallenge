#include <bits/stdc++.h>

int minSumPath(vector<vector<int>> &grid) {
    int n=grid.size(), m=grid[0].size();
    vector<int> prev(m,0);
    for(int i=0; i<n; i++){
        vector<int> curr(m,0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0){
                curr[j]=grid[i][j];
            }
            else{
                int up=INT_MAX,left=INT_MAX;
                if(i>0) up=prev[j];
                if(j>0) left=curr[j-1];

                curr[j]= min(up, left) + grid[i][j];
            }
        }
        prev=curr;
    }
    return prev[m-1];
}