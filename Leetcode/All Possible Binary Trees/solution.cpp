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
    vector<TreeNode*> allPossibleFBT(int n) {
        
        // This is a code to generate all possible binary tree with n vertices/ nodes
         if(n % 2 == 0)
             return {};
        if(n == 1)
            return {new TreeNode()};
        
        
        // This is our result of Root nodes of all possible binary trees
        vector<TreeNode*> res;
        
        // We are iterating over all the nodes from n = 1 till n - 1 and using DP kind of solution
        for(int i=1; i<n-1; i+=2)
        {
            // All possible left anf right binary search trees
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - i - 1);
            
            for(auto l : left)
            {
                for(auto r : right)
                {
                    TreeNode* root = new TreeNode();
                    root -> left = l;
                    root -> right = r;
                    res.push_back(root);
                }
            }
        }
        
        // Return the result 
        return res;
            
    }
};