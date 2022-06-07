#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n=input.length();
    unordered_set<char> s;
    int i=0, j=0;
    int len=0;
    while(j<n && i<n){
        if(s.find(input[j])!=s.end()){
            while(input[i]!=input[j]){
                s.erase(input[i]);
                i++;
            }
            s.erase(input[i]);
            i++;
        }else{
            s.insert(input[j]);
            len= max(len,j-i+1);
            j++;
        }
    }
    return len;
}