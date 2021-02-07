#include <stdlib.h>

//Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* root = new ListNode(0, NULL);
		ListNode* l_new = root;
		int offset = 0;
		while(l1 && l2)
		{
			int sum = l1->val + l2->val + offset;
			offset = sum / 10;
			sum = sum% 10;
			l_new->next = new ListNode(sum, NULL);
			l_new = l_new->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		ListNode* l3 = l1;
		if(l1 == NULL)
			l3 = l2;
		while(l3)
		{
			if(offset == 0)
			{
				l_new->next = l3;
				break;
			}
			int sum = l3->val + offset;
			offset = sum / 10;
			sum = sum% 10;
			l_new->next = new ListNode(sum, NULL);
			l_new = l_new->next;
			l3 = l3->next;
		}
		if(offset)
		{
			l_new->next = new ListNode(offset, NULL);
		}

		l_new = root->next;
		delete root;
		return l_new;
    }
};
