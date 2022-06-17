/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL) return false;
    if(root->data ==x) return true;
    if(root->data > x) return searchInBST(root->left, x);
    return searchInBST(root->right,x);
}

//METHOD 2
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
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
*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root==NULL) return false;
    while(root!=NULL){
        if(root->data==x) return true;
        if(root->data>x) root=root->left;
        else root=root->right;
    }
    return false;
}