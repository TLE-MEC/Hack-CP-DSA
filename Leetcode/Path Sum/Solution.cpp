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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL){
            return false; // we have reached null after leaf node
        }else if(root->left == NULL && root->right == NULL && targetSum - root->val == 0){ 
            return true;
        }else{
            return hasPathSum(root->left, targetSum - root->val) ||  //Using recursion
                   hasPathSum(root->right, targetSum - root->val);   //In the end it will either return true or false
        }
    }
};
