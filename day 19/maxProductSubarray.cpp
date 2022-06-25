int maximumProduct(vector<int> &arr, int n)
{
    int ans=INT_MIN;
    for(int i=0; i<n; i++){
        ans=max(ans, arr[i]);
    }
    int curmx=1, curmn=1;
    for(auto i : arr){
        if(i<0){
            int temp= curmx;
            curmx=max(curmn*i, i);
            curmn=min(temp*i, i);
        }
        else{
            curmn=min(curmn*i, i);
            curmx=max(curmx*i, i);
        }
        ans=max(ans, curmx);
    }
    return ans;
}
