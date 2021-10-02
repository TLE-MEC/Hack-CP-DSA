class Solution 
{
    public:
        int diameter = 0;
        
        // FUNCTION TO TRAVERSE THE BINARY TREE. (DFS TRAVERSAL)
        int traversal(TreeNode* root,int height)
        {
            if(root == NULL)
            {
                return 0;
            }
            
            int l = traversal(root->left,height); // MAX - HEIGHT OF THE LEFT SUBTREE FROM THE CURRENT NODE.
            int r = traversal(root->right,height); // MAX - HEIGHT OF THE RIGHT SUBTREE FROM THE CURRENT NODE.
            
            diameter = max(diameter,l+r); // CHECKING IF THE THE CURRENT DIAMETER IS GREATER.
            
            return 1+max(l,r); 
        }
        
        int diameterOfBinaryTree(TreeNode* root) 
        {
            traversal(root,0);
            return diameter;
        }
};
