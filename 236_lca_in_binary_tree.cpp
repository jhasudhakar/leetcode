#include<stdlib.h>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode (int x):val (x), left (NULL), right (NULL)
  {
  }
};

class Solution
{
	private:
		TreeNode* lca;
public:
	TreeNode * lowestCommonAncestor (TreeNode * root, TreeNode * p,TreeNode * q)
	{
		lca = NULL;
		post_order(root, p, q);
		return lca;
	}

	int  post_order(TreeNode* node, TreeNode* p, TreeNode* q)
	{
		int l_ret_val = 0;
		if(node->left)
		{
			l_ret_val = post_order(node->left, p, q);
			if(l_ret_val == 3)
				return 3;
		}
		int r_ret_val = 0;
		if(node->right)
		{
			r_ret_val = post_order(node->right, p, q);
			if(r_ret_val == 3)
				return 3;
		}
		if((l_ret_val == 1 && q == node) || (l_ret_val == 2 && p == node))
		{
			lca = node;
			return 3;
		}
		if((r_ret_val == 1 && q == node) || (r_ret_val == 2 && p == node))
		{
			lca = node;
			return 3;
		}
		if(l_ret_val + r_ret_val == 3)
		{
			lca = node;
			return 3;
		}
		if(l_ret_val != 0)
			return l_ret_val;
		else if(r_ret_val != 0)
			return r_ret_val;
		else
		{
			if(node == p)
				return 1;
			else if(node == q)
				return 2;
		}
		return 0;
	}
};
