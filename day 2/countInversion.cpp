#include <bits/stdc++.h> 
using namespace std;
#define ll long long

ll merge(ll *arr, ll*temp, int mid, int s, int e){
    int i=s, j=mid;
    ll ans=0;
    int c=s;
    while(i<mid && j<e){
        if(arr[i] <= arr[j]){
            temp[c]=arr[i];
            i++;
        }else{
            temp[c]=arr[j];
            j++;
            ans+=mid-i;
        }
        c++;
    }
    while(i<mid){
        temp[c]=arr[i];
        i++;c++;
    }
    while(j<e){
        temp[c]=arr[j];
        c++; j++;
    }
    for(int i=s; i<e; i++){
        arr[i]=temp[i];
    }
    return ans;
}



ll mergeSort(ll arr[], ll temp[], int s, int e){
    if(e-s==1) return 0;
    
    int mid= (e+s)/2;
    ll ans=0;
    ans+=mergeSort(arr,temp,s, mid);
    ans+=mergeSort(arr,temp,mid, e);
    ans+=merge(arr, temp, mid, s,e);
    return ans;
    
}


long long getInversions(long long *arr, int n){
    // Write your code here.
    if(n==1) return 0;
    ll temp[n]={0};
    return mergeSort(arr, temp, 0,n);
}