#include <bits/stdc++.h>
int minCharsforPalindrome(string str) {
    string ns= str + "#";
    reverse(str.begin(), str.end());
    ns=ns+str;
    int n= ns.size();
    vector<int> lps(n,0);
    for(int i=1; i<n; i++){
        int lst= lps[i-1];
        while(lst>0 && ns[i]!=ns[lst]) lst--;
        
        if(ns[i]==ns[lst]) lst++;
        lps[i]=lst;
    }
    return str.size()-lps.back();
}
