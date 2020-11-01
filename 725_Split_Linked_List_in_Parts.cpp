
// 725. Split Linked List in Parts  ==> 725_Split_Linked_List_in_Parts.cpp

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
	vector<ListNode*> splitListToParts(ListNode* root, int k)
	{
		vector<ListNode*> ret_list;
		if(root == NULL) 
		{
			for(unsigned int n = 0; n<k; n++)
			{
				ret_list.push_back(NULL);	
			}
			return ret_list;
		}

		unsigned int len = 0;
		ListNode* tmp = root;
		while(tmp != NULL)
		{
			tmp = tmp->next;
			len++;
		}

		unsigned int part_len = len / k;
		unsigned int extra = len % k;
		tmp = root;
		while(tmp != NULL)
		{
			ListNode* new_start = tmp;
			unsigned int cur_len = part_len;
			if(extra)
			{
				cur_len = part_len + 1;
				extra--;
			}
			for(unsigned int i=1; i<cur_len; i++)
			{
				tmp = tmp->next;
			}

			ListNode* next = tmp->next;
			tmp->next = NULL;
			tmp = next;

			ret_list.push_back(new_start);
		}
		for(unsigned int n = ret_list.size(); n<k; n++)
		{
			ret_list.push_back(NULL);	
		}
		return ret_list;
	}
};