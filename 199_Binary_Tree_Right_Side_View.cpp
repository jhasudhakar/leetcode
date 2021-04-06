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
	vector<int> rightSideView(TreeNode* root)
   	{
		std::vector<TreeNode*>* level_nodes = new  std::vector<TreeNode*> ();
		std::vector<TreeNode*>* level_nodes = new  std::vector<TreeNode*> ();
		
		std::vector<int> right_view;
		if(root == NULL)
			return right_view;

		level_nodes.push_back(root);
		while(level_nodes->size())
		{
			right_view.push_back(level_nodes->at(level_nodes.size()-1);

		}

	}
};
