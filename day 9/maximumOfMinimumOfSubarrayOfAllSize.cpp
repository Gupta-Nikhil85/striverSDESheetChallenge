//Method 1 O(N^2)

#include <bits/stdc++.h>
int minCalc(vector<int> &a, int k){
    int n=a.size();
    deque<int> dq;
    int ans=INT_MIN;
    int i=0,j=0;
    while(j<n){
        while(!dq.empty() && dq.back()>a[j]){
            dq.pop_back();
        }
        dq.push_back(a[j]);
        if(j-i+1==k){
            ans=max(ans, dq.front());
            if(dq.front()==a[i]){
                dq.pop_front();
            }
            i++;
        }
        j++;
    }
    return ans;
}

vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(minCalc(a,i));
    }
    return ans;    
}


//Method 2 O(N)

#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n) {
    //find the span of each element 
    //find the size in which it is minimum element and 
    //update the value accordingly.
    vector<int> left(n,-1),right(n,n);
    stack<int> lef, rig;
    lef.push(0);
    for(int i=1; i<n; i++){
        while(!lef.empty() && a[lef.top()]>=a[i]){
            lef.pop();
        }
        if(!lef.empty()) left[i]=lef.top();
        lef.push(i);
    }
    rig.push(n-1);
    for(int i=n-2; i>=0; i--){
        while(!rig.empty() && a[rig.top()]>=a[i]){
            rig.pop();
        }
        if(!rig.empty()) right[i]=rig.top();
        rig.push(i);
    }
    vector<int> ans(n,INT_MIN);
    for(int i=0; i<n; i++){
        ans[right[i]-left[i]-2]=max(ans[right[i]-left[i]-2], a[i]);
    }
    //-2 for zero based
    for(int i=n-2; i>=0; i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    return ans;
}