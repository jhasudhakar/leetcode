/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *        *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *         *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *          * };
 *           */
class Solution
{
public:

	int kth_val(TreeNode* root, int&val, int k)
	{
		if(root == NULL)
			return 0;

		int lsize = kth_val(root->left, val, k);
		if(k == lsize+1)
		{
			val = root->val;
			return 1+lsize;
		}
		if(lsize+1 < k)
		{
			int rsize = kth_val(root->right, val, k-1-lsize);
			return lsize+rsize+1;
		}
		else
			return 0;
	}

  int kthSmallest (TreeNode * root, int k)
  {
	  int ret_val = 0;
	  kth_val(root, ret_val, k);
	  return ret_val;
  }
};
