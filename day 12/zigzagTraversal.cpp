/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    if(root==NULL) return ans;
    int lvl=0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size= q.size();
        vector<int> temp;
        for(int i=0; i<size; i++){
            Node* n= q.front();
            q.pop();
            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
            temp.push_back(n->data);
        }
        if(lvl%2){
            for(int i=size-1; i>=0; i--){
                ans.push_back(temp[i]);
            }
        }else{
            for(int i=0; i<size; i++){
                ans.push_back(temp[i]);
            }
        }
        lvl++;
    }
    return ans;
}
