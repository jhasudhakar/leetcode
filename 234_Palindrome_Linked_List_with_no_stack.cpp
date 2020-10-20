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
#include<vector>
class Solution
{
	public:

		bool isPalindrome(ListNode* head)
		{
			if(head == NULL)
			{
				return true;
			}

			ListNode* start1 = NULL, *start2 = NULL;
			ListNode *prev = NULL, *slow = head, *next = slow->next;
			ListNode *fast = head->next; 
			if(fast == NULL)
			{
					return true;
			}
			slow->next = prev;
			while(fast->next != NULL)
			{
				fast = fast->next->next;
				if(fast == NULL) // Odd no of elements;
				{
					start2 = next->next; // skip the common mid element.
					break;
				}

				prev = slow;
				slow = next;
				next = slow->next;
				slow->next = prev;
			}
			if(start2 == NULL)
			{
				start2 = next;
			}
			start1 = slow;
			while(start1 != NULL && start2 != NULL)
			{
				if(start1->val != start2->val)
					return false;

				start1 = start1->next;
				start2 = start2->next;
			}
			if(start1 || start2)
				return false;
			return true;
		}

};