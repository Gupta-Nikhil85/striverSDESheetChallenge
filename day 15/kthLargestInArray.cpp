int partition(int left, int right, vector<int> &nums){
        int pivot= nums[left];
        int l=left+1, r=right;
        while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot){
                swap(nums[l--], nums[r--]);
            }
            if(nums[l]>=pivot) l++;
            if(nums[r]<=pivot) r--;
        }
        swap(nums[r], nums[left]);
        return r;
    }    

int kthLargest(vector<int>& nums, int size, int k)
{
	int left= 0, right=nums.size()-1;
    while(true){
        int idx= partition(left, right, nums);
        if(idx==k-1) return nums[idx];
        else if(idx < k-1){
            left=idx+1;
        }
        else right=idx-1;
    }
    return -1;
}