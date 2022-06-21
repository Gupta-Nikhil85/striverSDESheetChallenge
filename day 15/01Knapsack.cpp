int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{    
    vector<int> prev(w+1,0), cur(w+1,0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            int take=0;
            if(weights[i-1] <= j){
                take= prev[j-weights[i-1]] + values[i-1];
            }
            int notTake= prev[j];
            cur[j]=max(take, notTake);
        }
        prev=cur;
    }
    return prev[w];
}