// 24. Swap Nodes in Pairs ==> 24_Swap_Nodes_in_Pairs.cpp

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
    ListNode* swapPairs(ListNode* head) {

    	if(head == NULL) return head;
    	ListNode root(0, head);
    	ListNode* parent = &root;
    	while(parent->next && parent->next->next)
    	{
    		ListNode* n1 = parent->next;
    		ListNode* n2 = n1->next;

    		n1->next = n2->next;
    		n2->next = n1;
    		parent->next = n2;
    		parent = n1;
    	}
      return root.next;

    }
};