#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
typedef BinaryTreeNode<int> Node;

void inorder(Node* root, int key, int&pre, int&suc){
    if(root==NULL) return;
    inorder(root->left, key, pre, suc);
    if(root->data < key){
        pre=max(pre, root->data);
    }
    if(root->data > key){
        suc= min(suc, root->data);
    }
    inorder(root->right, key, pre, suc);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    int pre=-1, suc=INT_MAX;
    Node* cur= root;
    inorder(root, key, pre, suc);
    if(suc==INT_MAX) suc=-1;
    return make_pair(pre, suc);
}
