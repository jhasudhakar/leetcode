/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
	public:
	ListNode* reverseBetween(ListNode* head, int m, int n)
	{
		ListNode root(0, head);

		ListNode* cur = &root;
		int pos = 0;
		while(pos+1 != m)
		{
			cur = cur->next;	
			pos++;
		}
		ListNode* parent1 = cur;
		pos++;
		cur = cur->next;

		ListNode* new_end = cur;
		ListNode* prev = NULL, *next = NULL;
		while(pos <=n)
		{
			next = cur->next ;
			cur->next = prev;
			prev = cur;
			cur = next;
			pos++;
		}

		parent1->next = prev;
		new_end->next = cur;
		return root.next;
	}
};

