// 109. Convert Sorted List to Binary Search Tree
// Given the head of a singly linked list where elements are sorted in ascending order, 
// convert it to a height balanced BST.
// For this problem, a height-balanced binary tree is defined as a binary tree 
// in which the depth of the two subtrees of every node never differ by more than 1.

# include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

// if the tree was already built, we would have used inorder traversal to fill it out
// but since it is not, and we want a height balanced tree, we need to find midpoint for
// each sub-list we are passing to the function for every recursive call

class Solution {
public:
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(!head)
            return NULL; // if head is a null pointer, the root will be a null pointer i.e. no tree
        
        if(!head->next)
            return new TreeNode(head->val); // if there is only one node in the linked list, there will be only the root node => no children
            // also, with the constructor used, left and right nodes are (nullptr) so we don't have to worry about reference values
        
        // list will have at least 2 nodes at this point
        // head->[]->[]->null (at least)
        ListNode* slow = head;
        ListNode* fast = head->next->next; // if we start at head like floyd's cycle detection algo
        // it becomes an infinite loop
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // cout << slow->val << "\n";
        
        TreeNode* root = new TreeNode(slow->next->val); // fast was one step ahead initially while finding the midpoint.
        // so the actual midpoint will be slow->next
        root->right = sortedListToBST(slow->next->next); // recursively build the right tree first 
        // the right part of the linked list ends naturally
        slow->next = NULL; // but we have to break off the left part or the left tree will consist of the entire 
        // list => not actually good to break off the input list
        root->left = sortedListToBST(head); // then use head to build the left list
        
        return root;  
    }
};