/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if root is null i.e reached the leaf node and couldn't find the nodes p and q
        // if root is p i.e q has not appeared before which means p is the common ancestor of p and q
        if(root == NULL || root == p || root == q)
            return root;
        TreeNode *l, *r;
        l = lowestCommonAncestor(root->left,p,q);
        r = lowestCommonAncestor(root->right,p,q);
        if(!l)      // if l is null, means node from right subtree is either p, q or NULL
            return r;
        if(!r)      // if r is null, means node from left subtree is either p, q or NULL
            return l;
        return root;
    }
};
