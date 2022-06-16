#include<bits/stdc++.h>

/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
typedef TreeNode<int> Node;

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));
    map<int, vector<int>> m;
    while(!q.empty()){
        int size=q.size();
        for(int i=0; i<size; i++){
            Node* f= q.front().first;
            int d= q.front().second;
            m[d].push_back(f->data);
            if(f->left) q.push(make_pair(f->left,d-1));
            if(f->right) q.push(make_pair(f->right, d+1));
            q.pop();
        }
    }
    for(auto x : m){
        auto v= x.second;
        for(int i=0; i<v.size(); i++){
            ans.push_back(v[i]);
        }
    }
    return ans;
}