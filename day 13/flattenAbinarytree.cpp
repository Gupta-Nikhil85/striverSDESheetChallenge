/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return root;
    if(root->left==NULL) {
        root->right= flattenBinaryTree(root->right);
        return root;
    }
    if(root->right==NULL) {
        root->right=flattenBinaryTree(root->left);
        return root;
    }
    TreeNode<int> *left= flattenBinaryTree(root->left);
    TreeNode<int> *right= flattenBinaryTree(root->right);
    
    root->right=left;
    while(left->right!=NULL){
        left=left->right;
    }
    left->right=right;
    return root;
}


//Method 2 Iterative way

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return root;
    TreeNode<int> *prev=NULL;
//     flatten(root, prev);
    stack<TreeNode<int>*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode<int>* cur=st.top();
        st.pop();
        if(cur->right) st.push(cur->right);
        if(cur->left) st.push(cur->left);
        if(!st.empty()){
            cur->right=st.top();
            cur->left=NULL;
        }
    }
    return root;
}

//Method 3
/************************************************************

    Following is the TreeNode class structure.

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

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return root;
    TreeNode<int>* cur=root;
    while(cur!=NULL){
        if(cur->left!=NULL){
            TreeNode<int>* prev=cur->left;
            while(prev->right!=NULL){
                prev=prev->right;
            }
            prev->right=cur->right;
            cur->right=cur->left;
        }
        cur=cur->right;
    }
    return root;
}
