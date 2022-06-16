
void helper(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &cur,  vector<vector<int>> &ans){
    if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0 || cur[i][j]==1) return;
    
    if(i==n-1 && j==n-1){
        vector<int> temp;
        cur[i][j]=1;
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                temp.push_back(cur[a][b]);
            }
        }
        ans.push_back(temp);
        cur[i][j]=0;
        return;
    }
    cur[i][j]=1;
    helper(i+1,j, n, maze, cur,ans);
    helper(i-1,j, n, maze, cur,ans);
    helper(i,j+1, n, maze, cur,ans);
    helper(i,j-1, n, maze, cur,ans);
    cur[i][j]=0;
}


vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> cur(n,vector<int>(n,0));
    helper(0,0,n,maze,cur,ans);
    return ans;
}