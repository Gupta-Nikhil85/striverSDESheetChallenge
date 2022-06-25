int f(int n, int target, vector<int> &v, vector<vector<int>> &dp){
    if(target==0) return 1;
    if(n==0) {
        if(v[0]==target) return 1;
        else return 0;
    }
    if(dp[n][target]!=-1) return dp[n][target];

    int notTake= f(n-1, target, v, dp);
    int take=0;
    if(target>=v[n]){
        take=f(n-1, target-v[n],v, dp);
    }
    return dp[n][target]= take + notTake;
}

bool subsetSumToK(int n, int target, vector<int> &v) {
    // Write your code here.
//     vector<vector<int>> dp(n,vector<int> (target+1,-1));
//     return f(n-1, target, v, dp) > 0;
    
//     vector<vector<bool>> dp(n,vector<bool> (target+1,false));
        
//         for(int i=0; i<n; i++){
//             dp[i][0]=true;
//         }
//         if(v[0]<=target){
//             dp[0][v[0]]=true;
//         }

//         for(int i=1; i<n; i++){
//             for(int j=1; j<=target; j++){
//                 bool notTake= dp[i-1][j];
//                 bool take= false;
//                 if(v[i] <=j){
//                     take= dp[i-1][j-v[i]];
//                 }
//                 dp[i][j]= take | notTake;
//             }
//         }
//     return dp[n-1][target];


    vector<bool> prev(target+1, false);
    prev[0]=true;

    if(v[0]<=target){
        prev[v[0]]=true;
    }
    for(int i=1; i<n; i++){
        vector<bool> curr(target+1, false);
        curr[0]=true;
        for(int j=1; j<=target; j++){
            bool notTake=prev[j];
            bool take=false;
            if(v[i]<=j){
                take=prev[j-v[i]];
            }
            curr[j]=take | notTake;
        }
        prev=curr;
    }
    return prev[target];


}