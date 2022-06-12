int search(int* arr, int n, int key) {
    // Write your code here.
    int low=0, high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        if(arr[mid]>=arr[low]){
            if(arr[mid] > key && arr[low] <=key) high=mid-1;
            else low=mid+1;
        }
        else{
            if(arr[mid] < key && arr[high] >=key) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}