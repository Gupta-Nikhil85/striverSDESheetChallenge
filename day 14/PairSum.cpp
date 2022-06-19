//METHOD 1
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(vector<int> &v,BinaryTreeNode<int>* root){
    if(root==NULL) return;
    inorder(v,root->left);
    v.push_back(root->data);
    inorder(v, root->right);
}


bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    vector<int> v;
    inorder(v, root);
    int i=0, j=v.size()-1;
    while(i<j){
        if(v[i]+v[j]==k) return true;
        else if(v[i]+v[j]>k) j--;
        else i++;
    }
    return false;
}


//METHOD 2 USING BST ITERATOR
#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/

void pushLeft(BinaryTreeNode<int>* root, stack<BinaryTreeNode<int>*> &st){
    while(root!=NULL){
        st.push(root);
        root=root->left;
    }
}
void pushRight(BinaryTreeNode<int>* root, stack<BinaryTreeNode<int>*> &st){
    while(root!=NULL){
        st.push(root);
        root=root->right;
    }
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    stack<BinaryTreeNode<int>* > next, before;
    pushLeft(root, next);
    pushRight(root, before);
    while(!next.empty() && !before.empty() && next.top()!=before.top()){
        BinaryTreeNode<int>* i= next.top();
        BinaryTreeNode<int>* j= before.top();
        if(i->data + j->data ==k) return true;
        if(i->data + j->data > k){
            before.pop();
            pushRight(j->left, before);
        }
        else{
            next.pop();
            pushLeft(i->right, next);
        }
    }    
    return false;
}