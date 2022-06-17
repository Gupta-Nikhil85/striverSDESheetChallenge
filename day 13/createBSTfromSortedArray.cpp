/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* createBST(vector<int>&arr, int st, int en){
    if(st>en) return NULL;
    int mid= (st+en)/2;
    TreeNode<int> *root= new TreeNode<int>(arr[mid]);
    root->left= createBST(arr, st, mid-1);
    root->right= createBST(arr, mid+1, en);
    return root;    
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    if(n==0) return NULL;
    return createBST(arr, 0, n-1);
    
}