#include<stdlib.h>
#include <vector>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
 
  TreeNode ():val (0), left (NULL), right (NULL)
  {
  }
 
  TreeNode (int x):val (x), left (NULL), right (NULL)
  {
  }
 
  TreeNode (int x, TreeNode * left, TreeNode * right):val (x), left (left),
    right (right)
  {
  }
};

class Solution
{
public:
  vector < int >rightSideView (TreeNode * root)
  {
	vector<int> rval;
    vector < TreeNode * > *layer_cur = new vector<TreeNode*>;
    vector < TreeNode * > *layer_nxt = new vector<TreeNode*>;
	if(root == NULL)
		return rval;
	layer_cur->push_back(root);
	while(layer_cur->size())
	{
		for(int i=0; i<layer_cur->size(); i++)
		{
			TreeNode* tnode = layer_cur->at(i);
			if(tnode->left)
				layer_nxt->push_back(tnode->left);
			if(tnode->right)
				layer_nxt->push_back(tnode->right);
		}
		rval.push_back((layer_cur->at(layer_cur->size()-1))->val);
		layer_cur->clear();
		vector< TreeNode * > *tmp = layer_cur;
		layer_cur = layer_nxt;
		layer_nxt = tmp;
	}
	delete layer_cur;
	delete layer_nxt;
	return rval;
  }
};


