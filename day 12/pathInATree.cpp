/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
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
*/
typedef TreeNode<int> Node;

void pathFinder(Node* root, int x, vector<int> &ans, vector<int> cur){
    if(root==NULL) return;
    if(root->data==x){
        for(auto a : cur){
            ans.push_back(a);
        }
        ans.push_back(x);
        return;
    }
    cur.push_back(root->data);
    if(root->left) pathFinder(root->left, x, ans, cur);
    if(root->right) pathFinder(root->right, x, ans, cur);
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    pathFinder(root, x, ans, vector<int>());
    return ans;
}
