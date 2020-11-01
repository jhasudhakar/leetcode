
// 328. Odd Even Linked List ==> 328_Odd_Even_Linked_List.cpp

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
	ListNode* oddEvenList(ListNode* head)
	{
		if(head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode odd_root(0, NULL);
		ListNode even_root(0, NULL);
		ListNode *even_prev = &even_root;
		ListNode *odd_prev = &odd_root;
		int count = 1;
		while(head != NULL)
		{
			if(count % 2)
			{
				odd_prev->next = head;
				odd_prev = odd_prev->next;
			}
			else
			{
				even_prev->next = head;
				even_prev = even_prev->next;	
			}
			head = head->next;
			count++;
		}
		even_prev->next = NULL;
		odd_prev->next = even_root.next;
		return odd_root.next;
	}
};