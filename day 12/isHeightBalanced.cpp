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
typedef BinaryTreeNode<int> Node;

pair<int,bool> helper(Node* root){
    if(root==NULL) return make_pair(0,true);
    pair<int,bool> left= helper(root->left);
    pair<int,bool> right= helper(root->right);
    return make_pair((max(left.first, right.first)+1),(left.second && right.second && (abs(left.first-right.first)<=1)));
    
}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    if(root==NULL) return true;
    return helper(root).second;
}