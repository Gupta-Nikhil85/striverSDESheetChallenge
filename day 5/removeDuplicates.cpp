int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
    int i=0, j=1;
    for(i=1; i<n; i++){
        if(arr[i]!=arr[i-1])j++;
    }
    return j;
}