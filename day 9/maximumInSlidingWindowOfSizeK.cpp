#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    deque<int> dq;
    vector<int> ans;
    int i=0,j=0;
    while(j<nums.size()){
        while(dq.size()!=0 && dq.back()<nums[j]){
            dq.pop_back();
        }
        dq.push_back(nums[j]);
        if(j-i+1==k){
            ans.push_back(dq.front());
            if(nums[i]==dq.front()){
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
}