bool findPattern(string p, string s)
{
    int n=p.size();
    vector<int> lps(n,0);
    for(int i=1; i<n; i++){
        int len= lps[i-1];
        while(len>0 && p[i]!=p[len]) len--;
        if(p[i]==p[len]) len++;
        lps[i]=len;
    }
    int i=0, j=0;
    while(i<s.size()){
        if(s[i]==p[j]){
            i++;
            j++;
        }
        else if(j!=0){
            j=lps[j-1];
        }else{
            i++;
        }
        if(j==n) return true;
    }
    return false;
}