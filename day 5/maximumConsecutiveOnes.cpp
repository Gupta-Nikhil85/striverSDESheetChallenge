int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i=0, j=0;
    int kmx=k, ans=0;
    while(i<n && j<n){
        if(arr[j]==1){
            j++;
            ans=max(j-i, ans);
        }else{
            if(k){
                k--;
                ans=max(ans, j-i+1);
                j++;
            }else{
                if(arr[i]==0){
                    if(k<kmx){
                        k++;
                    }
                }
                i++;
            }
        }
    }
    return ans;
}
