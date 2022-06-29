#include <bits/stdc++.h>
/*
    Time complexity: O(N) 
    Space complexity: O(N)
    
    Where 'N' is the number of nodes in the given binary tree.
*/

//  Function which helps in filling the required path in the stack.
bool helper(TreeNode<int> *root, stack<TreeNode<int> *> &st, TreeNode<int> *leaf)
{
    // Push the current node i.e "root" into the stack.
    st.push(root);

    // Check if it is a leaf node of the given binary tree.
    if (root->left == NULL && root->right == NULL)
    {
        // Check if this leaf is the given leaf node then return true.
        if (root->data == leaf->data)
        {
            return true;
        }
        // Else, pop-out the current node from the stack and then return false.
        else
        {
            st.pop();
            return false;
        }
    }
    
    // Variables to store the result obtained from left and right subtree calls.
    bool left = false, right = false;

    // Call for the left subtree, if there exists left child.
    if(root->left!=NULL){
        left = helper(root->left, st, leaf);
    }
    // If found the required path then return true.
    if (left)
    {
        return true;
    }

    // Call for the right subtree, if there exists right child.
    if(root->right!=NULL){
        right = helper(root->right, st, leaf);
    }
    // If found the required path then return true.
    if (right)
    {
        return true;
    }

    // Otherwise, pop-out the current node from the stack and then return false.
    st.pop();
    return false;
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    // If the root is NULL then return root itself.
    if (root == NULL)
    {
        return root;
    }

    // Stack that will store the path which includes the given leaf node.
    stack<TreeNode<int> *> st;

    // Call the helper function.
    helper(root, st, leaf);

    // Node that holds the new Root i.e. the given leaf node.
    TreeNode<int> *newRoot = st.top();
    st.pop();

    // Node that stores the parent of the current node while inverting the given binary tree.
    TreeNode<int> *parent = newRoot;

    while (!st.empty())
    {
        // Node that stores the current node.
        TreeNode<int> *curNode = st.top();
        st.pop();

        if (curNode->left == parent)
        {
            curNode->left = NULL;
            parent->left = curNode;
        }
        else
        {
            curNode->right = curNode->left;
            curNode->left = NULL;
            parent->left = curNode;
        }

        parent = parent->left;
    }

    return newRoot;
}