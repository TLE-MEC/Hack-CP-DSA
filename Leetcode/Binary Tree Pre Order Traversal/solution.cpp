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
    vector<int> preorderTraversal(TreeNode* root) {
        
        // Preorder means - Value print first, then Left Subtree and Right Subtree (V, L , R)
        // So our order of stack would be Vertex, Right, Left like this
        
        // We are doing it non - recursively therefore using stack for maintainenence of nodes order
        stack<TreeNode*> s;
        s.push(root);
        
        vector<int> ans;
        if(root == NULL)
            return ans;
        
        TreeNode* curr = root;
        while(!s.empty())
        {
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            
            // Visit right first because in stack the order is reversed
            if(curr -> right != NULL)
            {
                s.push(curr->right);
            }

            // then visit left, so ultimately left comes before right in stack
            if(curr -> left != NULL)
            {
                s.push(curr->left);    
            }
        }
        
        // answer vector is returned
        return ans;
        
    }
};