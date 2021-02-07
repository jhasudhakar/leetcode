class Solution {

	int cur_val = INT_MIN;
	bool skip_once = true;
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
			return true;

		bool ret = isValidBST(root->left);
		if(ret == false) 
			return false;
		if(skip_once == true) {
			cur_val = root->val;
			skip_once = false;
		} else {
			if(cur_val >= root->val)
				return false;
		}
		return isValidBST(root->right);
    }
};
