class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr) /* if input tree is empty or by recursive function we reaches till end without returning  false in middle then obviously both trees are equal hence return true */
        {
            return true;
        }
        if (p == nullptr || q == nullptr) /* if one node has value but other is equal to NULL then nodes aren't identical, hence trees are different */
        {
            return false;
        }
        if (p->val != q->val) // if any of the value mismatches, then return false as trees are not identical
        {
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right); /*both right node and left node must pass the above checks hence check for both nodes */
    }
};