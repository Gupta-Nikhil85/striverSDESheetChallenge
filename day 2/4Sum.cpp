// #include <bits/stdc++.h> 
// string fourSum(vector<int> arr, int target, int n) {
//     // Write your code here.
//     sort(arr.begin(), arr.end());
//     for(int i=0; i<n-3; i++){
//         for(int j=i+1; j<n-2; j++){
//             int l=j+1, r=n-1;
//             int val=target- (arr[i]+arr[j]);
//             while(l<r){
//                 if(arr[l]+arr[r]==val) return "Yes";
//                 else if(arr[l]+arr[r]>val) r--;
//                 else l++;
//             }
//         }
//     }
//     return "No";
// }

#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    unordered_map<int, vector<pair<int,int>>> m;
    
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int val= target-arr[i]-arr[j];
            if(m.find(val)!=m.end()){
                for(auto p : m[val]){
                    if(p.first !=i && p.second!=j){
                        return "Yes";
                    }
                }
            }
            m[arr[i]+arr[j]].push_back({i,j});
        }
    }
    return "No";   
}