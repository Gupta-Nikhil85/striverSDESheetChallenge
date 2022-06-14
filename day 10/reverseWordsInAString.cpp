#include<bits/stdc++.h>

string reverseString(string str)
{
    // Write your code here.
    stack<string> st;
    int j=0; string s="";
    while(j<str.length()){
        if(str[j]==' '){
            st.push(s);
            s="";
        }
        else s+=str[j];
        j++;
    }
    st.push(s);
    str="";
    while(!st.empty()){
        if(st.top()!="") str+=st.top()+' ';
        st.pop();
    }
    return str;
}