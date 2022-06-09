void f(vector<int> &num, vector<int> &ans,int i, int n, int sum){
    if(n==i){
        ans.push_back(sum);
        return;
    }
    f(num, ans,i+1, n, sum);
    f(num, ans, i+1, n, sum+num[i]);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    f(num, ans,0, num.size(),0);
    sort(ans.begin(),ans.end());
    return ans;
}