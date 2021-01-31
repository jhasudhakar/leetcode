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
    ListNode* rotateRight(ListNode* head, int k)
	{
		if(head == NULL)
			return NULL;
	
		int n=1;
		ListNode *tmp = head, *end_ptr = NULL;
		while(tmp->next != NULL)
		{
			n++;
			tmp = tmp->next;
		}
		end_ptr = tmp;

		k = k%n;
		if(k == 0)
		{
			return head;
		}
		int pos= (n-k);
		tmp = head;
		while(pos>1)
		{
			tmp = tmp->next;
			pos--;
		}
		ListNode* new_head = tmp->next;
		tmp->next = NULL;
		end_ptr->next = head;
		return new_head;
    }
};
