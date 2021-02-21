#include<stdlib.h>


//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    void reorderList(ListNode* head) {
		ListNode* root = new ListNode(0, head);
		ListNode* slow = root, *fast = root;
		while(fast && fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		if(fast && fast->next) // odd no of nodes
		{
			slow = slow->next; // Median element;
		}
		ListNode* prev = NULL, *cur = slow->next, *next = NULL;
		slow->next = NULL;
		while(cur != NULL)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
		}

		ListNode *l1 = head;
		ListNode *l2 = prev;
		ListNode *l = root;
		while(l1 && l2)
		{
			l->next = l1;
			l1 = l1->next;
			l = l->next;

			l->next = l2;
			l2 = l2 ->next;
			l = l->next;
		}
		l->next = l1; // As it may have nodes if list is odd size.
		head = root->next;
		delete root;
    }
};
