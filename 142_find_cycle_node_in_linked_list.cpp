#include <stdlib.h>
// Definition for singly
struct ListNode
{
	int val;
	ListNode * next;
	ListNode (int x):val (x), next (NULL) {}
};

class Solution
{
public:
  ListNode * detectCycle (ListNode * head)
  {
	if(head == NULL || head->next == NULL)
		return NULL;
	ListNode* slow = head;
	ListNode* fast = head->next->next;
	bool is_loop = false;
	while(slow && fast)
	{
		if(slow == fast)
		{
			is_loop = true;
			break;
		}

		slow = slow->next;
		if(fast->next)
		{
			fast = fast->next->next;
		}
		else
		{
			break;
		}

	}
	if(is_loop == false)
		return NULL;

	int loop_node_count = 0;
	do
	{
		slow = slow->next;
		loop_node_count++;

	} while(slow != fast);
	ListNode* zero_index_ptr = new ListNode(0);
	zero_index_ptr->next = head;
	slow = fast = zero_index_ptr;
	while(loop_node_count)
	{
		loop_node_count--;
		slow = slow->next;
	}
	while(slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	delete [] zero_index_ptr;
	return slow;
  }
};
