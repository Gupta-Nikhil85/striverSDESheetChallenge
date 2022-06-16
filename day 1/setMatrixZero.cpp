#include <bits/stdc++.h> 
using namespace std;

void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    int n= matrix.size();
    int m= matrix[0].size();
    bool col=false , row=false;
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j]==0){
                matrix[0][j]=0;
                matrix[i][0]=0;
                if(i==0) row=true;
                if(j==0) col=true;
            }
        }
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(matrix[0][j]==0 || matrix[i][0]==0){
                matrix[i][j]=0;
            }
        }
    }
    if(row==true){
        for(int j=0; j<m; j++){
            matrix[0][j]=0;
        }
    }
    if(col==true){
        for(int i=0; i<n; i++){
            matrix[i][0]=0;
        }
    }
}