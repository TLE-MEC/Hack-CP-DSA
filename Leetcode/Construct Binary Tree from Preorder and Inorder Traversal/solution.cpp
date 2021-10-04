class Solution {
public:
    unordered_map<int, int>mp;
    int preIndex = 0;
    //is is the starting index of the inorder 
    //ie is the ending index of the inorder
    TreeNode*buidTreeFromPre(vector<int>& preorder, unordered_map<int, int>&mp, int is, int ie){
         if(is > ie) return NULL; // we can't build any tree in this case
        TreeNode* root = new TreeNode(preorder[preIndex++]);// make trhe first index element as root from the preorder.
        if(is  == ie) return root;
        int mid = mp[root->val];// the mid will be the preorder first index 
        root->left =  buidTreeFromPre(preorder, mp, is, mid-1);
        //recursively call for starting index to mid-1 ->they will be the left subtree
        root->right = buidTreeFromPre(preorder, mp, mid+1, ie);//recursively call for mid+1 to ending index -> this will be our right subtree
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //map inorder 
        for(int i =0; i< inorder.size() ; i++){
            mp[inorder[i]] = i;
            //map value of node corresponding to it's indexing.
        }
        return buidTreeFromPre(preorder, mp, 0, preorder.size()-1);
    }
};