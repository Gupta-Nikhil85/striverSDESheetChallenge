#include <bits/stdc++.h>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
// 	// Write your code here.
//     priority_queue<int, vector<int>, greater<int>> q;
//     for(int i=0; i<n; i++){
//         for(int j=0; j<n; j++){
//             q.push(a[i]+b[j]);
//             if(q.size()>k) q.pop();
//         }
//     }
//     vector<int> ans;
//     while(!q.empty()){
//         ans.push_back(q.top());
//         q.pop();
//     }
//     reverse(ans.begin(), ans.end());
//     return ans;
priority_queue<int>pq;
    vector<int>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pq.push(a[i]+b[j]);
        }
    }
    for(int i=0;i<k;i++){
        int a=pq.top();
        pq.pop();
        v.push_back(a);
    }
    return v;
    
    
    }
