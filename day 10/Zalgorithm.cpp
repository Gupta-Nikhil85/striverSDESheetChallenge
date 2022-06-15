#include<bits/stdc++.h>

vector<int> calculateZ(string newStr){
    int size=newStr.length();
    vector<int> Z(size,0);
    Z[0]=0;
    int left=0,right=0;
    for(int k=0; k<size; k++){
        if(k>right){
            left=right=k;
            while(right<size && newStr[right]==newStr[right-left]){
                right++;
            }
            Z[k]=right-left;
            right--;
        }else{
            int k1=k-left;
            if(Z[k1]<right-k+1){
                Z[k]=Z[k1];
            }else{
                left=k;
                while(right<size && newStr[right]==newStr[right-left]){
                    right++;
                }
                Z[k]=right-left;
                right--;
            }
        }
    }
    return Z;
}

int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string newStr= p+ '$'+s;
    int ans=0;
    vector<int> Z= calculateZ(newStr);
    for(int i=0; i<n+m+1; i++){
        if(Z[i]==m) ans++;
    }
    return ans;
}