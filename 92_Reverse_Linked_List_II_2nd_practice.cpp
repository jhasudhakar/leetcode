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
    ListNode* reverseBetween(ListNode* head, int m, int n)
	{
    	ListNode* root = new ListNode(0, head); 
		ListNode* tmp = root;
		n = n-m+1;
		while(m-1>0)
		{
			tmp = tmp->next;
			m--;
		}
		ListNode* prev_start = tmp;
		ListNode* prev = NULL, *cur = tmp->next, *next = NULL;
		while(n)
		{
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			n--;
		}
		//Once loop finishes, prev points to last reversed node.
		prev_start->next->next = cur;
		prev_start->next = prev;;
		head = root->next;
		delete root;
		return head;
    }
};
