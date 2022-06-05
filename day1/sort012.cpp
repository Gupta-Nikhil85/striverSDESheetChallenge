#include <bits/stdc++.h> 
using namespace std;
void sort012(int *arr, int n)
{
   //   Write your code here
    int zero=-1, one=0, two=n-1;
    while(one<=two){
        if(arr[one]==1){
            one++;
        }
        else if(arr[one]==0){
            swap(arr[zero+1], arr[one]);
            zero++;
            one++;
        }
        else{
            swap(arr[two], arr[one]);
            two--;
        }
    }
}