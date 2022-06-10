string kthPermutation(int n, int k) {
    // Write your code here.
    k--;
    int fac=1;
    vector<int> v;
    for(int i=1; i<n; i++){
        fac*=i;
        v.push_back(i);
    }
    v.push_back(n);
    string ans="";
    while(true){
        int idx= k/fac;
        ans+=to_string(v[idx]);
        v.erase(v.begin()+idx);
        k=k%fac;
        if(v.size()==0) break;
        fac/=v.size();
    }
    return ans;
}
