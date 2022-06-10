bool isSafe(vector<vector<int>> &mat, int idx, int col, vector<int>&color){
    for(int i=0;  i<mat[idx].size(); i++){
        if(mat[idx][i]==1){
            if(col==color[i]) return false;
        }
    }
    return true;
}

bool solve(vector<vector<int>> &mat, int m,int idx,vector<int>&color){
    if(idx==mat.size()){
        return true;
    }
    for(int i=1; i<=m; i++){
        if(isSafe(mat,idx, i, color)){
            color[idx]=i;
            if(solve(mat, m, idx+1, color)) return true;
            else
            color[idx]=0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> color(mat.size(),0);
    return solve(mat, m,0, color) ? "YES" :"NO";
}