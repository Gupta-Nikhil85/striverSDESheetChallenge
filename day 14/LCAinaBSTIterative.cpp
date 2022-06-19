/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    if(!root||!P||!Q || root==P || root==Q) return root;
    
    while(root!=NULL)
    {
        if(root->data>P->data && root->data>Q->data)
            root=root->left;
        else if(root->data<P->data && root->data<Q->data)
            root=root->right;
        else
            return root;
    }
    return root;
}
