class Solution {
public:
//Recursive Solution 
//Time complexity- Worst case: O(n^2)
    vector<vector<int>> ret; 
     void BuildOrder(TreeNode* root,int level) 
    {
        //If the root is NULL then the pointer gets returned
        if(root == NULL) return;
        if(ret.size() == level)                         //Check for the size if its equal to the passed level
            ret.push_back(vector<int>());               // push the current element from back into vector and increase its size by 1
    
        ret[level].push_back(root->val);                // At the current level push the value of root into the vector from back
        BuildOrder(root->left, level + 1);              // Recursively traverse the left subtree 
        BuildOrder(root->right, level + 1);             // recursively traverse the right subtree
    }
    
    vector<vector<int>> levelOrder(TreeNode *root) {
        BuildOrder(root, 0);                            // Calling Buildorder function with initial level passed as 0
        return ret;
    }
};