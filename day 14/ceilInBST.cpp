#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

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
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/


int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans=INT_MAX;
    while(node){
        if(node->data==x) return x;
        else if(node->data > x){
            ans=min(ans,node->data);
            node=node->left;
        }else if(node->data < x){
            node=node->right;
        }
    }
    return ans==INT_MAX ? -1 :ans;
}