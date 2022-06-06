#include <bits/stdc++.h> 
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	int x=0;
    for(auto a : arr){
        x^=a;
    }
    for(int i=1; i<=n; i++){
        x^=i;
    }
    
    int rsb=0;
    int index = 0;
    while ((~x) & 1) {
        x >>= 1;
        index++;
    }
    rsb=1<<index;
    int n1=0,n2=0;
    for(auto a : arr){
        if(a&rsb){
            n1^=a;
        }
        else{
            n2^=a;
        }
    }
    for(int i=1; i<=n; i++){
        if(i&rsb){
            n1^=i;
        }else{
            n2^=i;
        }
    }
    for(auto a : arr){
        if(a==n1){
            return {n2,n1};
        }
        else if(a==n2){
            return {n1,n2};
        }
    }
    return {n1,n2};
}
