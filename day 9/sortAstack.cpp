#include <bits/stdc++.h>

void insertAtcorrectPosition(stack<int> &s,int t){
    if(s.empty() || s.top()<t) {
        s.push(t);
        return;
    }
    int t2= s.top();
    s.pop();
    insertAtcorrectPosition(s,t);
    s.push(t2);
}


void sortStack(stack<int> &s)
{
	// Write your code here
    if(s.size()<=1) return;
    int t= s.top();
    s.pop();
    sortStack(s);
    insertAtcorrectPosition(s, t);
    return;
}