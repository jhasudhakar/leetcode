#include<stdlib.h>


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
	int max_sum;
public:
	int max_path_sum(TreeNode* node)
	{
		if(node == NULL)
			return INT_MIN;
		int left_sum = max_path_sum(node->left);
		int right_sum = max_path_sum(node->right);

		int max_sum_here = node->val;
		if(left_sum > 0)
			max_sum_here += left_sum;
		if(right_sum > 0)
			max_sum_here += right_sum;
		if(max_sum_here > max_sum)
			max_sum = max_sum_here;

		int max_val = 0;
		if(left_sum > right_sum)
			max_val = left_sum;
		else
			max_val = right_sum;
		if(max_val < 0)
			max_val = 0;
		return max_val+node->val;

	}
  	int maxPathSum (TreeNode * root)
  	{
		max_sum = INT_MIN;
		max_path_sum(root);
		return max_sum;

  	}
};
