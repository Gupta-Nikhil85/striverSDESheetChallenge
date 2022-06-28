#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans="";
    int sz=arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<arr[0].size(); i++){
        if(arr[0][i]==arr[sz-1][i]){
            ans+=arr[0][i];
        }else break;
    }
    return ans;
}


