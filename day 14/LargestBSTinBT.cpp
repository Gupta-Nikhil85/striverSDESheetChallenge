/************************************************************

    Following is the Binary Tree node structure
    
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
class info{
  public:
    bool isBST;
    int mx;
    int mn;
    int size;
};

info helper(TreeNode<int>* root){
    if(root==NULL) return {true, INT_MIN, INT_MAX, 0};
    info left= helper(root->left);
    info right= helper(root->right);
    info cur;
    if(left.isBST && right.isBST && root->data > left.mx && root->data < right.mn){
        cur.size=left.size+ right.size +1;
        if(left.mn==INT_MAX) cur.mn=root->data;
        else cur.mn= left.mn;
        if(right.mx==INT_MIN) cur.mx= root->data;
        else cur.mx=right.mx;
        cur.isBST= true;
    }
    else{
        cur.isBST=false;
        cur.mn==INT_MIN;
        cur.mx==INT_MAX;
        cur.size= max(left.size, right.size);
    }
    return cur;
}

int largestBST(TreeNode<int>* root) 
{
    info ans= helper(root);
    return ans.size;
}
