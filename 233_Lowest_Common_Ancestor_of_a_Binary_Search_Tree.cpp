#include <stdlib.h> 
// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {

    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
  		if(root == NULL)
	  		return NULL;
		TreeNode* lp = lowestCommonAncestor2(root->left, p, q);
		TreeNode* rp = lowestCommonAncestor2(root->right, p, q);
		if(lp && rp)
		{
			return root;
		}
		else if(lp)
		{
			if(root->val == q->val)
				return root;
			else
				return lp;
		}
		else if(rp)
		{
			if(root->val == p->val)
				return root;
			else
				return rp;
		}
		else
		{
			if(root->val == p->val || root->val == q->val)
				return root;
		}
		return NULL;

    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(p->val > q->val)
			return lowestCommonAncestor2(root, q, p);
		else
			return lowestCommonAncestor2(root, p, q);

	}
};
