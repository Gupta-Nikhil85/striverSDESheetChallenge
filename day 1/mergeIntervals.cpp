#include <bits/stdc++.h> 
using namespace std;
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.
    sort(intervals.begin(), intervals.end());
    int n=intervals.size();
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(ans.size()==0){
            ans.push_back(intervals[i]);
        }
        else{
            vector<int> p1= ans[ans.size()-1];
            vector<int> p2= intervals[i];
            if(p1[1] >= p2[0]){
                p1[1]=max(p1[1], p2[1]);
                ans[ans.size()-1]=p1;
            }else{
                ans.push_back(p2);
            }
        }
    }
    return ans;
}
