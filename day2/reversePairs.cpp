#include <bits/stdc++.h> 

int merge(vector<int> &arr, vector<int> &temp, int s, int mid, int e){
    
    int i=s,j=mid+1;
    int ans=0;
    for(i=s; i<mid+1; i++){
        while(j<=e && arr[i]>2LL*arr[j]){
            j++;
        }
        ans+=j-mid-1;
    } 
    i=s;j=mid+1; 
    int c=s;
    while(i<=mid && j<=e){
        if(arr[j] > arr[i]){
            temp[c]=arr[i];
            c++; i++;
        }else{
            temp[c]=arr[j];
            c++; j++;
        }
    }
    while(i<=mid){
        temp[c]=arr[i];
        i++;c++;
    }
    while(j<=e){
        temp[c]=arr[j];
        c++;j++;
    }
    for(int k=s; k<=e; k++){
        arr[k]=temp[k];
    }
    return ans;
}

int mergeSort(vector<int> &arr, vector<int> &temp, int s, int e){
    if(s>=e) return 0;
    int mid= (e-s)/2+s;
    int ans=0;
    ans+=mergeSort(arr, temp, s, mid);
    ans+=mergeSort(arr, temp, mid+1, e);
    ans+=merge(arr,temp,s,mid,e);
    return ans;
}


int reversePairs(vector<int> &arr, int n){
	// Write your code here.
    vector<int> temp(n,0);
    int ans= mergeSort(arr, temp, 0,n-1);
    return ans;
}