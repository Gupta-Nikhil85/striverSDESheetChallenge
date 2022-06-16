#include <bits/stdc++.h> 
using namespace std;

int findMajorityElement(int arr[], int n) {
	// Write your code here.
    if(n==1) return arr[0];
    int ele=arr[0],cnt=1;
    for(int i=1; i<n; i++){
        if(ele==arr[i]){
            cnt++;
        }else{
            cnt--;
        }
        if(cnt==0){
            ele=arr[i];
            cnt=1;
        }
    }
    cnt=0;
    for(int i=0; i<n; i++){
        if(ele==arr[i]) cnt++;
    }
    return cnt > n/2 ? ele : -1;
}