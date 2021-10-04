class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        // The base case which will be triggered at leaf nodes 
        if(root==null){
            return null; // The path just traversed doesn't contain the target so we return null
        }
        // Exact match to our target val, return the subtree rooted at the current node
        if(root.val==val){
            return root;
        }
        // Target not yet found, compare node.val to target and traverse the left/right subtrees accordingly
        if(root.val>val){
            return searchBST(root.left,val);
        }
        if(root.val<val){
            return searchBST(root.right,val);
        }
        return null;
    }
}