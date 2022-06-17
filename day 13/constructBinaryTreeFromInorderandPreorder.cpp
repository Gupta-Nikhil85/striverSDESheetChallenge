#include<bits/stdc++.h>
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
typedef TreeNode<int> Node;

Node* create(vector<int> &preorder,int &preidx ,int st, int en, unordered_map<int,int> &m){
    if(st>en) return NULL;
    Node* root= new Node(preorder[preidx]);
    preidx++;
    root->left= create(preorder,preidx,st, m[root->data]-1, m);
    root->right= create(preorder,preidx, m[root->data]+1,en, m);
    return root;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int,int> m;
    for(int i=0; i<inorder.size(); i++){
        m[inorder[i]]=i;
    }
    int preidx=0;
    return create(preorder,preidx, 0, inorder.size()-1, m);
}