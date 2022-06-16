//Return Subset Sum to K

void f(int i,vector<int> &arr, int n, int k,vector<int> &cur, vector<vector<int>> &ans){
    
    if(i==n){
        if(k==0){
            ans.push_back(cur);
        }
        return;
    }
    
    //TAKE
    cur.push_back(arr[i]);
    f(i+1, arr, n, k-arr[i],cur, ans);
    cur.pop_back();
    //NotTAKE
    f(i+1,arr,n,k,cur,ans);    
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> cur;
    f(0,arr,n,k,cur,ans);
    return ans;
}