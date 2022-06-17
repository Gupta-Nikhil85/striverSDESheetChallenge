#include <bits/stdc++.h>

/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* create(vector<int>& postOrder, unordered_map<int,int> &m, int st, int en, int &postIdx){
    if(st>en) return NULL;
    
    TreeNode<int>* root= new TreeNode<int>(postOrder[postIdx]);
    postIdx--;
    root->right= create(postOrder, m, m[root->data]+1, en, postIdx);
    root->left= create(postOrder, m, st, m[root->data]-1,postIdx);
    return root;
}


TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    unordered_map<int,int> m;
    for(int i=0; i<inOrder.size();i++){
        m[inOrder[i]]=i;
    }
    int postIdx=postOrder.size()-1;
    TreeNode<int>* root= create(postOrder, m, 0, postIdx, postIdx);
    return root;
}
