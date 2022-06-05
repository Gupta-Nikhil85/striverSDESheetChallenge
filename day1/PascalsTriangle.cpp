#include <bits/stdc++.h> 
using namespace std;

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long>> v;
    vector<long long> t= {1};
    v.push_back(t);
    if(n==1) return v;
    t={1,1};
    v.push_back(t);
    if(n==2) return v;
    for(int i=2; i<n; i++){
        vector<long long> temp;
        temp.push_back(1);
        for(int j=1; j<i; j++){
            temp.push_back(v[i-1][j-1]+ v[i-1][j]);
        }
        temp.push_back(1);
        v.push_back(temp);       
    }
    return v;    
}
