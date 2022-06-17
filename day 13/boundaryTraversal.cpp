/************************************************************

    Following is the Binary Tree node structure:
    
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
void traverseLeft(TreeNode<int>* root, vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    ans.push_back(root->data);
    if(root->left!=NULL){
        traverseLeft(root->left, ans);
    }else{
        traverseLeft(root->right, ans);
    }
}

void traverseLeaf(TreeNode<int>* root, vector<int>&ans){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(TreeNode<int>* root, vector<int> &rightrev){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    rightrev.push_back(root->data);
    if(root->right!=NULL){
        traverseRight(root->right, rightrev);
    }else{
        traverseRight(root->left, rightrev);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    vector<int> rightrev;
    traverseRight(root->right,rightrev);
    for(int i=rightrev.size()-1; i>=0; i--){
        ans.push_back(rightrev[i]);
    }
    return ans;
}