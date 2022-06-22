#include <bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> mx;
    priority_queue<int, vector<int>, greater<int>> mn;
    vector<int> ans;
    for(int i=0; i<n; i++){
        if(i%2){
            mx.push(arr[i]);
            mn.push(mx.top());
            mx.pop();
            ans.push_back((mx.top()+mn.top())/2);
        }
        else{
            mn.push(arr[i]);
            mx.push(mn.top());
            mn.pop();
            ans.push_back(mx.top());
        }
    }
    return ans;
}
