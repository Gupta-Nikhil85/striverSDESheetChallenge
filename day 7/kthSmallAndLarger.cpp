#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)

{

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for(int i=0; i<k; i++){
      maxHeap.push(arr[i]);
      minHeap.push(arr[i]);
  }

   for(int i=k; i<n; i++){
       if(maxHeap.top()>arr[i]){
           maxHeap.pop();
           maxHeap.push(arr[i]);
       }
       if(minHeap.top()<(arr[i])){
           minHeap.pop();
           minHeap.push(arr[i]);
       }
   }

    vector<int> res;

   res.push_back(maxHeap.top());
   res.push_back(minHeap.top());

  return res;

}