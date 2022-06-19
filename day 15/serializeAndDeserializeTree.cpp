#include <bits/stdc++.h>

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

string serializeTree(TreeNode<int> *root)
{
    if(root==NULL) return "";
    queue<TreeNode<int>*> q;
    q.push(root);
    string ans="";
    while(!q.empty()){
        TreeNode<int> *cur=q.front();
        q.pop();
        if(cur==NULL) ans+="#,";
        else{
            ans+=to_string(cur->data) + ",";
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
    if(serialized.length()==0) return NULL;
    stringstream s(serialized);
    string str;
    getline(s, str, ',');
    TreeNode<int>* root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<int>* cur= q.front();
        q.pop();
        getline(s, str, ',');
        if(str=="#") cur->left=NULL;
        else cur->left=new TreeNode<int>(stoi(str));
        getline(s, str, ',');
        if(str=="#") cur->right=NULL;
        else cur->right=new TreeNode<int>(stoi(str));
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
    }
    return root;
}



