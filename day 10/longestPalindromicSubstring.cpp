#include <bits/stdc++.h>
string solve(string str, int st, int e){
    if(st<0 || e>=str.length()) return "";
    while(st>=0 && e<str.length()){
        if(str[st]==str[e]){
            st--;
            e++;
        }else break;
    }
    return str.substr(st+1, e-st-1);
}

string longestPalinSubstring(string str)
{
    // Write your code here.
    int n=str.length();
    string len="";
    for(int i=0; i<n; i++){
        string odd= solve(str, i, i);
        string even=solve(str,i,i+1);
        string temp=even;
        if(odd.length()>even.length()) temp=odd;
        if(len.length()<temp.length()) len=temp;
    }
    return len;
}