// 160. Intersection of Two Linked Lists ==> 160_Intersection_of_Two_Linked_Lists.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <algorithm>
class Solution
{
	public:
		ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
		{
			unsigned int  c1 = 0;
			unsigned int  c2 = 0;

			ListNode* tmp = headA;
			while(tmp != NULL)
			{
				c1++;
				tmp = tmp->next;
			}
		
			tmp = headB;
			while(tmp != NULL)
			{
				c2++;
				tmp = tmp->next;
			}
			if(c1 == 0 || c2 == 0)
				return NULL;
			
			if(c1 > c2)
			{
				while(c1 != c2)
				{
					headA = headA->next;
					c1--;
				}
			}
			else
			{
				while(c1 != c2)
				{
					headB = headB->next;
					c2--;
				}	
			}

			while(headA != headB)
			{
				headA = headA->next;
				headB = headB->next;
			}
			return headA;
		}
};