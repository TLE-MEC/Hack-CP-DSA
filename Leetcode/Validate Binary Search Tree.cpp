class Solution {
public:
    bool check(TreeNode* root,long long int min,long long int max)
    {
        if(root==nullptr)
            return true;
        
        if(((long long int)root->val<=min)||((long long int)root->val>=max))
        {
            return false;
        }
        return ((check(root->left,min,(long long int)root->val))&&(check(root->right,(long long int)root->val,max)));
        
    }
    
    bool isValidBST(TreeNode* root) {
        if(root->left==nullptr  && root->right==nullptr)
            return true;
        if(!check(root,LLONG_MIN,LLONG_MAX))
        {
            return false;
        }
        return true;
    }
    
};
