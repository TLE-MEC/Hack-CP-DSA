// 108. Convert Sorted Array to Binary Search Tree
// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

// *
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };

/*
    Logic of this recursive solution:- 
        1. We are making the middle element of the sorted array as root node of BST
        2. Left half of the array is left subtree of array
        3. Right half of the array is right subtree of array
    with 2. & 3. we can say that BST's property is maintained since array is sorted

*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        /* we are calling the member function treeMake 
        passing the arguments nums, 0, size of num - 1 */
        return treeMake(nums, 0, nums.size()-1);
    }

    // treeMake function returns the root of the newly made BST(Binary Search Tree)
    TreeNode* treeMake(vector<int>& nums, int start, int end){

        //mid is middle index of the vector from start index to end index of nums
        int mid = (start + end)/2;

        /* till start index is less than or equal to end index
           we are making new TreeNode object with node value nums[mid],
           recursively calling treeMake function to add the nodes at:-
                root->left and
                root->right */ 
        if(start<=end){
            //we are making new TreeNode object with node element as nums[mid]
            TreeNode* root = new TreeNode(nums[mid]);

            //we are passing vector nums, start index, mid-1 index (denoting first half of vector)
            root->left = treeMake(nums, start, mid-1);

            //we are passing vector nums, mid+1 index, end index (denoting second half of vector)
            root->right = treeMake(nums, mid+1, end);

            //we are returning the new node made back to the previous function call
            return root;
        }
        //if start is greater than end, return NULL
        return NULL;
    }
};