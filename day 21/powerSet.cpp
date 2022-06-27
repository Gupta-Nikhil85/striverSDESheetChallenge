vector<vector<int>> pwset(vector<int>v)
{
    int n= v.size();
    int num=1<<n;
    vector<vector<int>> ans;
    for(int i=0; i<num; i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            if((i & 1<<j) !=0){
                temp.push_back(v[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}