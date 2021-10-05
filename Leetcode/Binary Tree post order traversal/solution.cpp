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
    vector<int> postorderTraversal(TreeNode* root) {
        
        // Postorder means - First Left Subtree and Right Subtree, then value of the node (L , R, V)
        // So our order of stack would be Vertex, Left, Right like this - because stack invert things up
        
        // We are doing it non - recursively therefore using stack for maintainenence of nodes order

        stack<TreeNode*> s;
        s.push(root);
        
        // answer vector to be returned
        vector<int> ans;
        
        if(root == NULL)
            return ans;
        
        TreeNode* curr;
        while(!s.empty())
        {
            curr = s.top();
            s.pop();

            // We push the value first here, but we will ultimately reverse the order at end
            ans.push_back(curr->val);
            
            // We are visit left node first - because in stack order is reversed
            if(curr -> left != NULL)
                s.push(curr->left);
            
            // and then we are visiting right
            if(curr -> right != NULL)
                s.push(curr->right);

            // So ultimately, when we start popping out of stack we get left side first and then right side
        }
        
        // reverse because we entered value first before visiting left and right subtrees
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};