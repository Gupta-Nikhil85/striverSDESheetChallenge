int upperBound(vector<int> arr, int value){
    int low=0, high=arr.size()-1;
    while(low<=high){
        int mid= (high-low)/2 + low;
        if(arr[mid] <= value) low=mid+1;
        else high=mid-1;
    }
    return low;
}


int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size(), m=matrix[0].size();
    int low=0, high=1e6;
    while(low<=high){
        int mid=(low+high)/2;
        int val=0;
        for(auto i :matrix){
            val+=upperBound(i, mid);
        }
        if(val<= (n*m)/2){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;    
}