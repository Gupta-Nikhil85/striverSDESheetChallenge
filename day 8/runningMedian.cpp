#include <bits/stdc++.h>

void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int,vector<int> ,greater<int>> mnheap;
    priority_queue<int> mxheap;
    
    for(int i=0; i<n; i++){
        int num=arr[i];
        if(mxheap.size()==0){
            mxheap.push(arr[i]);
        }
        else if(mxheap.size()>=mnheap.size()){
            mxheap.push(arr[i]);
            mnheap.push(mxheap.top());
            mxheap.pop();
        }
        else{
            mnheap.push(arr[i]);
            mxheap.push(mnheap.top());
            mnheap.pop();
        }   
        if(mxheap.size()==mnheap.size()) cout<<(mnheap.top()+mxheap.top())/2<<" ";
        else if(mxheap.size()>mnheap.size()) cout<<mxheap.top()<<" ";
        else cout<<mnheap.top()<<" ";
    }cout<<endl;
    return;    
}