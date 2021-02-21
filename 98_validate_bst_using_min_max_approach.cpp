#include<stdlib.h>
#include <stdint.h>

	// Definition for a binary tree node.
   struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	return isValidBST(root, INT64_MIN, INT64_MAX); 
    }
	bool isValidBST(TreeNode* node, int64_t MIN, int64_t  MAX)
	{
		if(node == NULL)
			return true;
		
		int64_t cur_val = node->val;

		bool ret = isValidBST(node->left, MIN, cur_val-1);	
		if(ret == false)
			return ret;

		if(MIN > cur_val || MAX < cur_val)
		{
			return false;
		}

		return isValidBST(node->right, cur_val + 1, MAX);
	}
};
