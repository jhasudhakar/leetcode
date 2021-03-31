#include <stdlib.h>
//Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode ():val (0), next (NULL)
  {
  }
  ListNode (int x):val (x), next (NULL)
  {
  }
  ListNode (int x, ListNode * next):val (x), next (next)
  {
  }
};

class Solution
{
public:
  ListNode * reverseKGroup (ListNode * head, int k)
  {
	if(k == 1 || head == NULL)
		return head;

	int len = 0;
	ListNode* tmp = head;
	while(tmp)
	{
		len++;
		tmp = tmp->next;
	}
	int reverse_count = len/k;
	if(reverse_count == 0)
		return head;

	ListNode* root = new ListNode(0, head);

	ListNode* p_sublist = root;
	ListNode* prev = NULL;
	ListNode* cur = head;
	ListNode* nxt = head->next;
	while(reverse_count)
	{
		for(int i=0; i<k; i++)
		{
			nxt = cur->next;
			cur->next = prev;
			prev = cur;
			cur = nxt;
		}
		
		// Fix the start and end of k-reversed list.
		ListNode* k_head = prev;
		ListNode* k_tail = p_sublist->next;
		p_sublist->next = k_head;
		k_tail->next = cur;
		
		p_sublist = k_tail;
		prev = NULL;
		reverse_count--;
	}
	head = root->next;
	delete root;
	return head;
  }
};
