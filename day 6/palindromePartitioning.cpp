#include <bits/stdc++.h>
bool isPalindrome(string s){
    int n=s.length();
    for(int i=0; i<n/2; i++){
        if(s[i]!=s[n-i-1]) return false;
    }
    return true;
}
void f(int idx, string s, vector<string> &cur, vector<vector<string>> &ans){
    if(idx==s.length()){
        ans.push_back(cur);
        return;
    }
    for(int i=idx; i<s.length(); i++){
        string left= s.substr(idx, i-idx+1);
        if(isPalindrome(left)){
            cur.push_back(left);
            f(i+1, s, cur, ans);
            cur.pop_back();
        }
    }
}


vector<vector<string>> partition(string &s) 
{
    vector<string> cur;
    vector<vector<string>> ans;
    f(0,s,cur,ans);
    return ans;
}