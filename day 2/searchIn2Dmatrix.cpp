#include <bits/stdc++.h> 
#include <vector>
using namespace std;

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    int s=0;
    int e=m*n-1;
    while(s<=e){
        int mid= (e-s)/2+s;
        int row=mid/n;
        int col=mid%n;
        if(mat[row][col]==target){
            return true;
        }
        else if(mat[row][col]<target){
            s=mid+1;
        }
        else e=mid-1;
    }
    return false;
}