#include <bits/stdc++.h> 
using namespace std;

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int left=0;
    int right=m-1;
    int top=0;
    int bottom=n-1;
    while(left<right && top<bottom){
        int val=mat[left][top];
        for(int j=left+1; j<=right; j++){
            int temp=mat[top][j];
            mat[top][j]=val;
            val=temp;
        }
        for(int i=top+1; i<=bottom; i++){
            int temp= mat[i][right];
            mat[i][right]=val;
            val=temp;
        }
        for(int j=right-1; j>=left; j--){
            int temp= mat[bottom][j];
            mat[bottom][j]=val;
            val=temp;
        }
        for(int i=bottom-1; i>=top; i--){
            int temp= mat[i][left];
            mat[i][left]=val;
            val=temp;
        }
        left++; right--; top++; bottom--;
    }
}