class Solution {
public:
   bool isMirror(TreeNode* root1,TreeNode *root2) { 
        if(root1 == NULL and root2 == NULL)   // if root1 and root2 are not present
            return true;    // nothing to compare with
        
        if(root1 and root2 and root1->val == root2->val) // if root1 and root2 are present
            // also root1's val is equal to root2's val then we recursively check
            return isMirror(root1->left, root2->right) and isMirror(root1->right, root2->left);
            // recursively comparing left with right nodes of left and right subtrees
            // and comparing right and left nodes of left and right subtrees
            
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root); // if isMirror is true return true else false
    }
    
    //Brute Force TLE
    // bool isSymmetric(TreeNode* root) {
    //     bool flag = false;
    //     while(root){
    //         if(root->left == root->right)
    //             flag = true;
    //     }
    //     return flag;
    // }
};