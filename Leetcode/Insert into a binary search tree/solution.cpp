class Solution {
public:
    // Recursive Solution
    // Time complexity- Average case(Balanced trees): O(logn) | Worst case(Skewed trees): O(n)
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) {
            //if the root is null, new node is created with the given val
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        
        //searching for the correct position
        if(root->val > val)                                  //if val is less than current val,
            root->left = insertIntoBST(root->left, val);     //then node is to be inserted in the left sub-tree
        else if(root->val < val)                             // else if val is greater than current val
            root->right = insertIntoBST(root->right, val);   // then node is to be inserted in the right sub-tree
        return root;
    }
};