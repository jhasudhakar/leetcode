#include<stdlib.h>
#include <climits>
#include<vector>
using namespace std;

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

	int cur_val = INT_MIN;
	bool skip_once = true;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
			return true;
		vector<TreeNode*> stk;
		stk.push_back(root);
		vector<bool> left_scan;
		left_scan.push_back(false);
		while(stk.size())
		{
			TreeNode* cur = stk[stk.size()-1];
			if(cur == NULL)
			{
				stk.pop_back();
				left_scan.pop_back();
				continue;
			}

			if(false == left_scan[stk.size()-1])
			{
				left_scan[stk.size()-1] = true;
				stk.push_back(cur->left);
				left_scan.push_back(false);
			}
			else
			{
				// 1/2: parse the current vale.
				stk.pop_back();
				left_scan.pop_back();
				if(skip_once == true)
				{
					skip_once = false;
					cur_val = cur->val;
				}
				else
				{
					if(cur_val >= cur->val)
						return false;
					cur_val = cur->val;
				}
				// 2/2: Add the right element to the list.
				stk.push_back(cur->right);
				left_scan.push_back(false);
			}

		}
		return true;

    }
};
