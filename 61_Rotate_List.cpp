
// 61. Rotate List  ==> 61. Rotate List

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
		ListNode* rotateRight(ListNode* head, int k){
			if(head ==NULL || head->next == NULL)
			{
				return head;
			}

			ListNode* tmp = head;
			ListNode* end = NULL;
			unsigned int len = 1;
			while(tmp->next != NULL)
			{
				tmp = tmp->next;
				len++;
			}
			end = tmp;

			k = k % len;
			if(k ==0)
				return head; // full rotation

			int shift = len - k;
			shift--; // to get the parent of the start of the shift;
			tmp = head;
			while(shift != 0)
			{
				tmp = tmp->next;
				shift--;
			}
			ListNode* new_head = tmp->next;
			tmp->next = NULL;
			end->next = head;
			return new_head;
		}
};