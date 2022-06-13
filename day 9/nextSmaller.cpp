#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    s.push(arr[n-1]);
    vector<int> ans(n,-1);
    for(int i=n-2; i>=0; i--){
        while(!s.empty() && s.top()>=arr[i]){
            s.pop();
        }
        if(!s.empty()) ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}