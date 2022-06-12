#include <bits/stdc++.h>

bool isPossible(vector<int> &positions, int val, int n, int c){
    int cnt=1;
    int prev=positions[0];
    for(int i=1; i<n; i++){
        if(positions[i]-prev>=val) {
            cnt++;
            prev=positions[i];
        }
    }
    return cnt>=c;
}


int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
    sort(positions.begin(), positions.end());
    int low=0, high=positions.back()-positions[0];
    int ans=0;
    while(low<=high){
        int mid= (low+high)/2;
        if(isPossible(positions, mid, n, c)){
            low=mid+1;
            ans=mid;
        }else high=mid-1;
    }
    return ans;
}