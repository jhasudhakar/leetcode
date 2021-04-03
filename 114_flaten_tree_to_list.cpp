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
	void flaten(TreeNode* tnode, TreeNode** lnode)
	{
		if(tnode == NULL)
			return;
		flaten(tnode->right, lnode);
		flaten(tnode->left, lnode);
		
		tnode->right = (*lnode);
		tnode->left = NULL;
		*lnode = tnode;
	}

	void flatten(TreeNode* root)
	{
		TreeNode* cur_node = NULL;
		flaten(root, &cur_node);
	}
};
