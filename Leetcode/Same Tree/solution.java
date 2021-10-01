/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

//Explaination
// Binary tree node structure is given above,
// Approach:
// This problem can be solved in recursive manner with O(n) time complexity and O(log(n)) space complexity.
// The recursive methods logic is very simple,
// 	1. Check if both treeNodes are null,if yes that means both trees are empty,so return true.
// 	2. if either one is null, that means both trees can never be same, so return false.
// 	3. Both trees will be same if treeNode values of both tree at every level is same, so check tree.val for both trees, if any time they are not equal, that means both trees can never be same, so return false.
// 	4. Last step is to recursively call the same function on left subtrees of both trees and right subtrees of both trees.If all left and right subtrees are following the above conditions then the function will return true , else 	false.

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
    // p and q are both null
   if (p == null && q == null) return true;
    // one of p and q is null
    if (q == null || p == null) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.right, q.right) &&
            isSameTree(p.left, q.left);
    }
}