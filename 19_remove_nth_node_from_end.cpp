class Solution
{
	public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* root = new ListNode(0, head);
		ListNode* fast_ptr = root;
		while(n)
		{
			fast_ptr = fast_ptr->next;
			n--;
		}
		ListNode* slow_ptr = root;
		while(fast_ptr->next != NULL)
		{
			fast_ptr = fast_ptr->next;
			slow_ptr = slow_ptr->next;
		}
		slow_ptr->next = slow_ptr->next->next;
		head = root->next;
		delete root;
		return head;
	}
};
