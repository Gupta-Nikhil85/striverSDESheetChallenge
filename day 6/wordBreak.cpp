#include<bits/stdc++.h>

void f(int idx, string &s, unordered_set<string> &st, vector<string> &ans, string cur){
    if(idx==s.length()){
        ans.push_back(cur);
        return;
    }
    
    for(int i=idx; i<s.length(); i++){
        string temp= s.substr(idx,i-idx+1);
        if(st.find(temp)!=st.end()){
            f(i+1, s, st, ans, cur+temp+" ");
        }
    }
    
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_set<string> st;
    for(auto i : dictionary) st.insert(i);
    vector<string> ans;
    string cur="";
    f(0,s,st,ans,cur);
    return ans;
}