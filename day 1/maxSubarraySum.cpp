#include <bits/stdc++.h> 
using namespace std;
long long maxSubarraySum(int arr[], int n)
{   
    long long sum=0;
    long long currsum=0;
    for(int i=0;i<n;i++){
        if(currsum<0) currsum=0;
        currsum+=arr[i];
        sum=max(currsum, sum);
    }
    return sum;
}