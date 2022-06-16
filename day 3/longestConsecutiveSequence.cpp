#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    unordered_map<int,int> m;
    for(auto x : arr){
        m[x]++;
    }
    int cnt=0, mx=1;
    for(auto x : arr){
        if(m.find(x-1)==m.end()){
            cnt=0;
            while(m.find(x)!=m.end()){
                cnt++;
                x++;
            }
        }
        else cnt=1;
        mx=max(mx,cnt);
    }
    return mx;
}