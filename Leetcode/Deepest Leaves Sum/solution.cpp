/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// Luvdipsingh Dadiyala (Github : luv2001)

#define rep(i,n) for(int i=0;i<(n);++i)

class Solution {
public:
	vector<vector<int>> levelOrderTriversal(TreeNode *root)
	{
		vector<vector<int>> ans;

		if (root == NULL)
		{
			return ans;
		}
		else
		{
			queue<TreeNode *> q;
			q.push(root);
			TreeNode *node;
			while (!q.empty())
			{
				vector<int> level;
				int size = q.size();
				rep(i, size)
				{
					TreeNode *node = q.front();
					q.pop();
					level.push_back(node->val);

					if (node -> left != NULL )
					{
						q.push(node->left);
					}
					if (node -> right != NULL)
					{
						q.push(node->right);
					}
				}
				ans.push_back(level);
			}
		}
		return ans;
	}
	int deepestLeavesSum(TreeNode* root) {

		vector<vector<int>> levelOrder = levelOrderTriversal(root);

		auto it = levelOrder.end() - 1;

		int sum = 0;
		for (auto it1 : *it)
		{
			sum = sum + it1;
		}
		return sum;

	}
};