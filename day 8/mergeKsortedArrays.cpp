#include <bits/stdc++.h>

typedef pair<int, pair<int,int>> p;

vector<int> mergeKSortedArrays(vector<vector<int>>&arr, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue< p, vector<p>, greater<p>> pq;
    for(int i=0; i<k; i++){
        p cur;
        cur.first=arr[i][0];
        cur.second.first=i;
        cur.second.second=0;
        pq.push(cur);
    }
    while(!pq.empty()){
        p cur= pq.top();
        pq.pop();
        ans.push_back(cur.first);
        if(arr[cur.second.first].size()-1> cur.second.second){
            cur.first=arr[cur.second.first][cur.second.second+1];
            cur.second.second++;
            pq.push(cur);
        }
    }
    return ans;
}
