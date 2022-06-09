#include <bits/stdc++.h>
bool comp(vector<int> j1, vector<int> j2){
    if(j1[1] > j2[1]) return true;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    vector<bool> slot(3010,false);
    sort(jobs.begin(), jobs.end(),comp);
    int ans=0;
    for(int i=0; i<jobs.size();i++){
        int j=jobs[i][0]-1;
        while(j>=0){
            if(slot[j]==false){
                slot[j]=true;
                ans+=jobs[i][1];
                break;
            }
            j--;
        }
    }
    return ans;
}
