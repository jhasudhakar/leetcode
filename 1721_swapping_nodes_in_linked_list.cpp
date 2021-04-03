class Solution
{
	public:
		ListNode* swapNodes(ListNode* head, int k)
		{
			ListNode* root = new ListNode(0, head);
			ListNode* k1 = NULL, *k2 = NULL;
			ListNode *fast_ptr = root, *slow_ptr = root;
			for(int i=0; i<k; i++)
				fast_ptr = fast_ptr->next;
			k1 = fast_ptr;

			while(fast_ptr != NULL)
			{

				fast_ptr = fast_ptr->next;
				slow_ptr = slow_ptr->next;
			}
			k2 = slow_ptr;
			int buf = k1->val;
			k1->val = k2->val;
			k2->val = buf;
			head = root->next;
			delete root;
			return head;

		}
};
