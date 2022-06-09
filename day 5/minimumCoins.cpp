int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[9]={1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int ans=0;
    for(int i=8; i>=0; i--){
        ans+=amount/coins[i];
        amount%=coins[i];
    }
    return ans;
}
