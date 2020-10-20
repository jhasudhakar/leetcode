/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
	Node* flatten(Node* head)
	{
		if(head == NULL)
				return head;
		vector<Node*> to_scan_next_ptr;
		to_scan_next_ptr.push_back(NULL);
		Node* cursor = head;

		while(to_scan_next_ptr.size())
		{
			while(cursor->next != NULL)
			{
				if(cursor->child)
				{
					to_scan_next_ptr.push_back(cursor);
					cursor = cursor->child;
				}
				else 
					cursor = cursor->next;
			}
			
			if(cursor->child != NULL)
			{
				to_scan_next_ptr.push_back(cursor);
				cursor = cursor->child;
			}
			else
			{
				// Next is null and child is null
				Node* linear_ref = to_scan_next_ptr[to_scan_next_ptr.size()-1];
				to_scan_next_ptr.pop_back();
				if(linear_ref == NULL)
						break;

				Node* linear_ref_next = linear_ref->next;
				Node* linear_ref_child = linear_ref->child;
				linear_ref->child = NULL;

				linear_ref->next = linear_ref_child;
				linear_ref_child->prev = linear_ref;
				

				cursor->next = linear_ref_next;
				if(linear_ref_next)
					linear_ref_next->prev = cursor;
			}
		}

		return head;
	}
};