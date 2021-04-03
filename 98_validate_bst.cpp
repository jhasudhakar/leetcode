#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

struct TreeNode {
 int val;
 TreeNode *left;
 TreeNode *right;
 TreeNode() : val(0), left(NULL), right(NULL) {}
 TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
	bool isValidBST(TreeNode* node, int min, int max)
	{
		if(node == NULL)
			return true;
		if(node->val < min || node->val > max)
			return false;
		if(node->left)
		{
			if(node->val == INT_MIN)
				return false;

			if(false == isValidBST(node->left, min, node->val -1))
				return false;
		}
		if(node->right)
		{
			if(node->val == INT_MAX)
				return false;
			return isValidBST(node->right, node->val+1, max);
		}
		return true;
	}
	bool isValidBST(TreeNode* root)
	{
		return isValidBST(root, INT_MIN, INT_MAX);
	}
};
