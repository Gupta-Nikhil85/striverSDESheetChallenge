#include <bits/stdc++.h>

int f(string s, string cur, vector<string>&ans, vector<bool>&visited){
    if(cur.length()==s.length()){
        ans.push_back(cur);
    }
    for(int i=0; i<s.length(); i++){
        if(!visited[i]){
            visited[i]=true;
            f(s,cur+s[i],ans, visited);
            visited[i]=false;
        }
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here
    vector<string> ans;
    vector<bool> visited(s.length(),false);
    f(s, "", ans, visited);
    return ans;    
}