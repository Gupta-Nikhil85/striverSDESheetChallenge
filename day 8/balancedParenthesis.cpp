#include <bits/stdc++.h>

bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    for( auto ch : expression){
        if(ch=='{' || ch=='(' || ch=='[') st.push(ch);
        else{
            if(st.empty()) return false;
            else{
                if(ch=='}' && st.top()=='{') st.pop();
                else if(ch==')' && st.top()=='(') st.pop();
                else if(ch==']' && st.top()=='[') st.pop();
                else return false;
            }
        }
    }
    return st.empty();
}