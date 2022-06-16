/*************************************************************
 
    Following is the Binary Tree node structure.

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
    };

*************************************************************/
typedef BinaryTreeNode<int> Node;

vector<int> bottomView(BinaryTreeNode<int> * root){
    map<int, int> m;
    queue<pair<Node*,int>> q;
    int lvl=0;
    q.push(make_pair(root, 0));
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size; i++){
            Node* cur= q.front().first;
            int d=q.front().second;
            q.pop();
            if(cur->left){
                q.push(make_pair(cur->left, d-1));
            } 
            if(cur->right) q.push(make_pair(cur->right, d+1));
            m[d]=cur->data;
        }
    }
    vector<int> ans;
    for(auto x : m){
        ans.push_back(x.second);
    }
    return ans;
}
