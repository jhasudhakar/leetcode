#include<stdlib.h>

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution
{
public:
    ListNode* swapNodes(ListNode* head, int k)
	{
		if(head == NULL)
			return NULL;

		ListNode* k1, *k2;
		ListNode* ptr1=head, *ptr2=head;
		int n = 1;
		while(n < k)
		{
			ptr2 = ptr2->next;
			n++;
		}
		k1 = ptr2;

		while(ptr2->next != NULL)
		{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		k2 = ptr1;
		int buf = k1->val;
		k1->val = k2->val;
		k2->val = buf;
		return head;
    }

};
