/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

pair<int,int> diameter(TreeNode<int>* root){
    if(root==NULL) return make_pair(0,0);
    pair<int,int> left= diameter(root->left);
    pair<int,int> right= diameter(root->right);
    int high= left.second+ right.second;
    return make_pair(max(left.first, max(right.first, high)),1 + max(left.second, right.second));
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
    return diameter(root).first;
}
