vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int> ans;
    int mod= (int) 1e9+7;
    int n=str.length(), m=pat.length();
    int p=31;
    vector<long long> power(n+1,1);
    for(int i=1; i<=n; i++){
        power[i]=(power[i-1]*p)%mod;    
    }
    vector<long long> h(n+1,0);
    for(int i=0; i<n; i++){
        h[i+1]= (h[i] + (str[i]-'A'+1)*power[i])%mod;
    }
    long long hashval=0;
    for(int i=0; i<m; i++){
        hashval= (hashval+(pat[i]-'A'+1)*power[i])%mod;
    }
    for(int j=0; j<n-m+1;j++){
        long long curhash= (h[j+m]-h[j]+mod)%mod;
        if(curhash==(hashval*power[j])%mod){
            ans.push_back(j);
        }
    }
    return ans;
}


//Method 2
#include <bits/stdc++.h>
vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int p=7;
    vector<int> ans;
    int mod= (int)1e9+7;
    int n=str.length(), m=pat.length();
    int hashpat=0,hashstr=0;
    for(int i=0; i<m; i++){
        hashpat=(hashpat + (pat[i]-'A'+1)* pow(p,i));
        hashstr=(hashstr + (str[i]-'A'+1)* pow(p,i));
    }
    if(hashpat==hashstr){
        bool isequal=true;
        for(int i=0; i<m; i++){
            if(str[i]!=pat[i]){
                isequal=false;
                break;
            }
        }
        if(isequal) ans.push_back(0);
    }
    for(int i=m; i<n; i++){
        hashstr= ((hashstr - (str[i-m]-'A'+1))/p + (str[i]-'A'+1)* pow(p,m-1));
        if(hashstr==hashpat){
            bool isequal=true;
            for(int j=0; j<m; j++){
                if(str[i+j-m+1]!=pat[j]){
                    isequal=false;
                    break;
                }
            }
            if(isequal) ans.push_back(i-m+1);
        }
    }
    return ans;
}
