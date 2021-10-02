
/*
Approach: The basic property of a BST is that all the nodes in the left subtree of a node have a value smaller or equal to the node
and all in the right subtree have greater or equal. 

An inorder traversal of a BST is defined as:
Recursively traverse all nodes in the left subtree, then the current node and then recursively the right subtree
Such a traversal always guarantees a non-decreasing order in which the nodes are visited.

Thus, to validate whether a given tree is a BST, we can perform the inorder traversal and check if it is in increasing order.
Note: Here we are checking for increasing rather than non-decreasing as in the problem it is given that the left subtree will have values strictly *less*
and right will have strictly *greater*.

Time Complexity: O(n) as both the inorder traversal and the increasing check is O(n)

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    vector<int> order; // vector used to store the inorder traversal
    void inorder(TreeNode *root)
    { // recursive function for inorder traversal
        if (root == NULL)
            return;
        inorder(root->left);
        order.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode *root)
    {
        inorder(root); // perform the inorder traveral on the given root
        for (int i = 0; i < order.size() - 1; i++)
        {
            if (order[i] >= order[i + 1])
                return false; // check if any 2 consecutive values in the array are non-increasing, if yes then the tree is not a BST
        }
        // all consecutive pairs are in increasing order hence the tree is a BST
        return true;
    }
};
