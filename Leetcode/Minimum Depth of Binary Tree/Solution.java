class Solution {
    public int minDepth(TreeNode root) {
        // base case returning 0 for null nodes
        if(root == null) return 0;
        
        // get the Left and Right heights of the tree
        int lH = minDepth(root.left);
        int rH = minDepth(root.right);
        
        // m is the minimum of left and right heights
        int m = Math.min(lH, rH);
        
        // we return 1 plus the minimum height
        // if the tree has 2 children 
        // else return the maximum height
        return 1+ (m > 0 ? m : Math.max(lH, rH));
    }
}
