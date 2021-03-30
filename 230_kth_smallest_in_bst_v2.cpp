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

	void kth_val(TreeNode* root, int&index, int k, int&val)
	{
		if(root == NULL)
			return;

		kth_val(root->left, index, k, val);
		index++;
		if(k == index)
		{
			val = root->val;
			return;
		}
		kth_val(root->right, index, k, val);
	}

  int kthSmallest (TreeNode * root, int k)
  {
	  int index = 0, val=0;
	  kth_val(root, index, k, val);
	  return ret_val;
  }
};
