// Recursive Approach:
// Find maximum depth of the left subtree and store it to a variable leftHeight lets say
// Similarly find maximum depth of the right subtree and save it
// Maximum depth for the current subtree will be maximum of leftDepth and rightDepth plus 1
// Add 1 to include the current node
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) 
            return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};