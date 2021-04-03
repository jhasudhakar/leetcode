#include<stdlib.h>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(NULL) {}
     ListNode(int x) : val(x), next(NULL) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution
{
	public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		if(l1 == NULL)
			return l2;
		else if(l2 == NULL)
			return l1;
		ListNode* root = new ListNode(0);
		ListNode* parent = root;
		int offset = 0;
		int sum = 0;
		while(l1 != NULL && l2 != NULL)
		{
			sum = offset + l1->val + l2->val; 
			offset = sum/10; 
			sum = sum % 10; 
			parent->next = new ListNode(sum);
			parent = parent->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* l3 = l1;
		if(l3 == NULL)
			l3 = l2;
		while(l3)
		{
			sum = offset + l3->val; 
			offset = sum/10;
			sum = sum % 10; 
			parent->next = new ListNode(sum);
			parent = parent->next;
			l3 = l3->next;
		}
		if(offset)
		{
			parent->next = new ListNode(offset);
		}
		ListNode* ret = root->next;
		delete root;
		return ret;
	}
};
