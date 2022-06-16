bool isSafe(int row,int col, vector<int> &sol, int n){
        
        //left
        
        for(int i=0; i<col; i++){
            if(sol[i]==row+1) return false;
        }
        
        //up diagonal
        for(int i=col-1,j=row-1; i>=0 && j>=0;){
            if(sol[i]-1==j) return false;
            i--;j--;
            // j--;
        }
        
        //down diagonal
        for(int i=col-1, j=row+1; i>=0 && j<n; i--){
            if(sol[i]-1==j) return false;
            j++;
        }
        return true;
        
    }

void recurQueens(int col, vector<vector<int>> &ans, vector<int> &sol, int n){
        if(col==n){
            vector<int> temp(n*n,0);
            for(int i=0; i<n; i++){
                temp[i*n+ sol[i]-1]=1;
            }
            ans.push_back(temp);
            return;
        }
        for(int row=0; row<n; row++){
            if(isSafe(row,col,sol,n)){
                sol.push_back(row+1);
                recurQueens(col+1,ans,sol,n);
                sol.pop_back();
            }
        }
    }

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> sol;
    recurQueens(0,ans,sol,n);
    return ans;
}