#include <stdlib.h>

//Definition for a binary tree node.
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
	bool isSmt(TreeNode* pre, TreeNode* pos)
	{
		if(pre == NULL && pos == NULL)
			return true;
		else if(pre == NULL || pos == NULL)
			return false;

		if(pre->val != pos->val)
			return false;
		if(false == isSmt(pre->left, pos->right))
			return false;
		return isSmt(pre->right, pos->left);

	}
	bool isSymmetric(TreeNode* root)
	{
		return isSmt(root, root);
	}
};
