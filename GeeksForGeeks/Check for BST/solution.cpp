public class Solution
{
    //Function to check whether a Binary Tree is BST or not.
    boolean isBST(Node root)
    {
        // code here.
       // Returns true if the given tree is a binary search tree
        return isBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    
    /* Returns true if the given tree is a BST and its values are >= min and <= max. */
    boolean isBST(Node root,long min , long max){
        /* an empty tree is BST */
        if(root==null)
        return true;
        
         /* false if this node violates the min/max constraint */
        if(root.data<=min || root.data>=max) return false;
        
         /* otherwise check the subtrees recursively, tightening the min or max constraint */
        return isBST(root.left,min,root.data) && isBST(root.right,root.data,max);
    }
}
