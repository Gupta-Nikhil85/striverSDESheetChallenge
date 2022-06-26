int unboundedKnapsack(int n, vector<int> &profit)
{
    vector<int> prev(n+1,0);
    for(int i=0; i<=n; i++){
        prev[i]=(i)*profit[0];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=n; j++){
            int notPick= prev[j];
            int pick= 0;
            if(i+1<=j){
                pick=prev[j-i-1]+profit[i];
            }
            prev[j]=max(pick, notPick);
        }
    }
    return prev[n];
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    return unboundedKnapsack(n,price);
}
