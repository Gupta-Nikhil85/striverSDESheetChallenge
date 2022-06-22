#include <bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int k;
    Kthlargest(int k, vector<int> &arr) {
        this->k=k;
        for(auto i : arr){
            q.push(i);
            if(q.size()>k) q.pop();
        }
    }

    void add(int i) {
        q.push(i);
        if(q.size()>k) q.pop();
    }

    int getKthLargest() {
        return q.top();
    }

};