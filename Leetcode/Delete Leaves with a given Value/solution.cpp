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
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        // Delete Leaves with a given value 
        
        // Check if only single root node is present
        if(root->left == NULL  && root->right == NULL)
        {
            if(root->val == target)
                return NULL;
            else
                return root;
        }
        
        // Pre - order traversal of the tree
        
        // Search for all the leaf nodes with the target value and delete them
        preorder(root, target, NULL, -1);
        if(root->left == NULL  && root->right == NULL)
        {
            if(root->val == target)
                return NULL;
            else
                return root;
        }

        // return the root node of the tree, so that changes can be observed 
        return root;
    }
    
    bool f = 0;
    void preorder(TreeNode* root, int target, TreeNode* par, int left)
    {   
        // Non - leaf nodes
        if(root == NULL)
            return;
        
        if(root->left)
        {
            preorder(root->left, target, root, 1);
        }
        if(root->right)
        {
            preorder(root->right, target, root, 0);
        }
        
        // Leaf Node
        if(root -> val == target && (root->left == NULL) && (root->right == NULL))
        {
            if(par != NULL)
            {
                if(left == 1)
                    par->left = NULL;
                else
                    par->right = NULL;
            }
        }
    }
};