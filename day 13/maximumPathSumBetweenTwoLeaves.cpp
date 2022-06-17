/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void leaves(TreeNode<int>* root, int&count){
    if(root==NULL) return;

    if(root->left==NULL && root->right==NULL){
        count++;
        return;
    }
    leaves(root->left, count);
    leaves(root->right, count);
}

pair<long long, long long> helper(TreeNode<int> * root){
    if(root==NULL) return make_pair(0,0);
    pair<long long, long long> left= helper(root->left);
    pair<long long, long long> right= helper(root->right);
    return make_pair(max(left.first+root->val, right.first+root->val), max(max(right.second, left.second), left.first+ right.first + root->val));
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return -1;
    int cnt=0;
    leaves(root, cnt);
    if(cnt==1) return -1;
    return helper(root).second;
}