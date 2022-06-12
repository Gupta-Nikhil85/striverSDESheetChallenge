// int uniqueElement(vector<int> arr, int n)
// {
// 	// Write your code here
//     int low=0, high=arr.size()-2;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(mid%2){
//             if(arr[mid-1]==arr[mid]) low=mid+1;
//             else high=mid-1;
//         }else{
//             if(arr[mid+1]==arr[mid]) low=mid+1;
//             else high=mid-1;
//         }
//     }
//     return arr[low];
// }
int uniqueElement(vector<int> arr, int n)
{
    // Write your code here
    int low=0, high=arr.size()-2;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==arr[mid^1]) low=mid+1;
        else high=mid-1;
    }
    return arr[low];
}
