/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

bool validateBST(BinaryTreeNode<int> *root) {
    if(root==NULL) return true;
    bool flag=true;
    if(root->left) flag=root->left->data <= root->data;
    if(root->right) flag= flag && (root->right->data >= root->data);
    return flag && validateBST(root->left) && validateBST(root->right);
}