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

		if(head == NULL || head->next == NULL)
			return ;

		ListNode* sp = head;
		ListNode* fp = head->next;
		while(fp->next != NULL && fp->next->next != NULL)
		{
			fp = fp->next->next;
			sp = sp->next;
		}
		if(fp->next != NULL)
		{
			sp = sp->next;
		}

		ListNode* l2 = sp->next;
		sp->next = NULL;

		ListNode* prev = NULL, *nxt = NULL;
		ListNode* cur = l2;
		while(cur != NULL)
		{
			nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
		l2 = prev;
		ListNode* root = new ListNode(0, head);
		cur = root;
		while(l2 != NULL)
		{
			cur->next = head;
			head = head->next;

			cur->next->next = l2;
			l2 = l2->next;
			cur = cur->next->next;
		}
		cur->next = head;
		head = root->next;
		delete root;
    }
};
