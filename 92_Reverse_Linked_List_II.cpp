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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
  		ListNode* root = new ListNode(0, head);
  		int index = 0;
  		ListNode* cur = root;

  		while(index < m-1 && cur != NULL) // loop till parent of m-th node.
  		{
  			cur = cur->next;
  			index++;
  		}

  		if(cur == NULL) // m is invalid
  		{	
  				delete root;
  				return head;
			}

  		ListNode* parent = cur;
  		cur = cur->next;
  		index++; // Equals m now.
  		ListNode* prev = NULL;
  		while(index <= n && cur != NULL)
  		{
  			index++;
  			ListNode* next = cur->next;
  			cur->next = prev;
  			prev = cur;
  			cur = next;
  		}

  		ListNode* new_end = parent->next;
  		parent->next = prev;
  		if(new_end)
  			new_end->next = cur;

  		head = root->next;
  		delete root;
  		return head;
    }
};