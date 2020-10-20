
  // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
#include<vector>
class Solution
{
	public:
		bool isPalindrome(ListNode* head)
		{
			if(head == NULL || head->next == NULL)
				return true;

			std::vector<int> stk;
			ListNode root(0, head);
			ListNode *jmp1 = &root, *jmp2 = &root;
			ListNode *start1 = head, *start2 = NULL;
			
			while(jmp2->next != NULL)
			{
				jmp2 = jmp2->next->next;
				if(jmp2 == NULL) // Odd no of nodes.
				{
					start2 = jmp1->next->next;
					break;
				}
				jmp1 = jmp1->next;
				stk.push_back(jmp1->val);

			}
			
			if(start2 == NULL)
				start2 = jmp1->next;
			while(start2 != NULL)
			{
				if(stk.size() && stk[stk.size()-1] == start2->val)
				{
					start2 = start2->next;
					stk.pop_back();
				}
				else
					return false;
			}
			if(stk.size())
					return false;
			return true;
		}
};