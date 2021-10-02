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

/*

Approach : Since We have to find sum of all the nodes at the last level, We can clearly see that We can use level order traversal and than return the sum of all the present element of last vector.

*/

#define rep(i,n) for(int i=0;i<(n);++i)

class Solution {
public:
	vector<vector<int>> levelOrderTriversal(TreeNode *root)	// Implimentation of Level Order Traversal
	{
		vector<vector<int>> ans;	// First We will initialize an empty vector of vectors.

		if (root == NULL)
		{
			return ans;		// If root is null (There is No Tree) We will return that empty vector of vectors ans.
		}
		else
		{

			// And if root is not null to level order traverse this tree We can do this steps :

			queue<TreeNode *> q;	// Initializing queue of data type TreeNode * to store temporary Tree Nodes
			q.push(root);			// Adding root element in queue
			TreeNode *node;			// Initializing an empty TreeNode

			/*
				Now We can check whether the Node has left or right elements or not and can easily add that to our current level vector and we can push back all these level vectors to the main ans vector.
			*/

			while (!q.empty())
			{
				vector<int> level;		// level vector to store current level
				int size = q.size();	// We will store the size of queue in size variable and will run the for loop to intract with each member and if they have left or right nodes we can push back them in queue and we'll add their values to current level till the queue becomes null.
				rep(i, size)
				{
					TreeNode *node = q.front();
					q.pop();
					level.push_back(node->val);	// Adding values to current level vector

					if (node -> left != NULL )
					{
						q.push(node->left);	// Checking whether node has left element or not, If there is we can simply push back into the queue.
					}
					if (node -> right != NULL)
					{
						q.push(node->right);	// Checking whether node has right element or not, If there is we can simply push back into the queue.
					}
				}
				ans.push_back(level);	// ans vector containes all level vectors from the starting node. Hence Level Order Traversal completed.
			}
		}
		return ans;
	}

	int deepestLeavesSum(TreeNode* root)
	{
		vector<vector<int>> levelOrder = levelOrderTriversal(root);	// First we traverse this tree in level order and will store that vector of vectors into levelOrder.

		auto it = levelOrder.end() - 1;		// it pointer points to last element of levelOrder vector which we might say collection of deepest elements. Now we just have to add them.

		int sum = 0;
		for (auto it1 : *it)
		{
			sum = sum + it1;		// Adding each element of last vector of levelOrder using simple for loop  which is our answer.
		}
		return sum;	// returning that values.

	}
};