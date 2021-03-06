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
    ListNode* deleteDuplicates(ListNode* head) {
		if(head == NULL)
		{
			return head;
		}
		ListNode* root = new ListNode(-102, head);
		ListNode* prev = root;
		ListNode* start = head;
		ListNode* end = start;
		while(start != NULL)
		{
			unsigned int dup = 0;
			while(end != NULL && (start->val == end->val))
			{
				end = end->next;
				dup++;
			}
			if(dup > 1) // Duplicates are there.
			{
				prev->next = end;
			}
			else
			{
				prev = start;
			}

			if(prev == NULL)
			{
				break;
			}
			start = end = prev->next;
		}
		head = root->next;
		delete root;
		return head;
    }
};

