#include <bits/stdc++.h> 
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    int slow=arr[arr[0]];
    int fast=arr[arr[arr[0]]];
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[arr[fast]];
    }
    slow=arr[0];
    while(slow!=fast){
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
}
