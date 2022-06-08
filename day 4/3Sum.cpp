#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
    sort(arr.begin(), arr.end());
    set<vector<int>> st;
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        int s=i+1,e=n-1;
        while(s<e){
            if(arr[s]+arr[e]==K-arr[i]){
                vector<int> temp={arr[i],arr[s],arr[e]};
//                 ans.push_back(temp);
                st.insert(temp);
                s++;e--;
            }
            else if(arr[s]+arr[e]>K-arr[i]) e--;
            else s++;
        }
    }
    for(auto i:st){
//         vector<int> temp={i.first, i.second.first, i.second.second};
        ans.push_back(i);
    }
    return ans;
}