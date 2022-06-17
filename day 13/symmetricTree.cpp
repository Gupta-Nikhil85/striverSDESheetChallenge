/*****************************************************

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
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool helper(BinaryTreeNode<int>* left, BinaryTreeNode<int>* right){
    if(left==NULL && right==NULL) return true;
    if(left==NULL || right==NULL) return false;
    return (left->data==right->data && (helper(left->left, right->right)) && helper(left->right, right->left));
}


bool isSymmetric(BinaryTreeNode<int>* root)
{
    return helper(root, root);
}