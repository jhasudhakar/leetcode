#include <stdlib.h>

// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(root == NULL)
			return NULL;
		TreeNode* lp = lowestCommonAncestor(root->left, p, q);
		TreeNode* rp = lowestCommonAncestor(root->right, p, q);
		if(lp && rp)
		{
			return root;
		}
		if(lp || rp)
		{
			if(p && p->val == root->val)
			{
				return root;
			}
			else if(q && q->val == root->val)
			{
				return root;
			}
			else if(lp)
				return lp;
			else
				return rp;
		}
		else // None of these are in the sub trees.
		{
			if(root->val == p->val || root->val == q->val)
				return root;
			else
				return NULL;
		}
    }
};
