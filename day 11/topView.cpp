#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
typedef TreeNode <int> Node;

vector<int> getTopView(TreeNode<int> *root) {
    map<int,int> m;
    vector<int> ans;
    if(root== NULL) return ans;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));
    while(!q.empty()){
        int size=q.size();
        for(int i=0; i<size;i++){
            Node* temp= q.front().first;
            int d=q.front().second;
            if(m.find(d)==m.end()){
                m[d]=temp->val;
            }
            q.pop();
            if(temp->left) q.push(make_pair(temp->left, d-1));
            if(temp->right) q.push(make_pair(temp->right,d+1));
        }
    }
    for(auto x : m){
        ans.push_back(x.second);
    }
    return ans;
}