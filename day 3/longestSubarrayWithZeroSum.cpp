#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) {

  // Write your code here
    unordered_map<int, int> m;
    int sum=0;
    int len=0;
    if(arr[0]==0){
        len=1;
    }
    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
        if(sum==0){
            len=max(len, i+1);
        }
        else if(m.find(sum)!=m.end()){
            len=max(len, i-m[sum]);
        }
        else{
            m[sum]=i;
        }
    }
    return len;

}