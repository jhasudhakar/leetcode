
// 138. Copy List with Random Pointer ==> 138_Copy_List_with_Random_Pointer.cpp


#include <iostream>
using namespace std;
#if 1
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
#endif

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)  return head;

        // Pass 1/4: Create list-2 with same value as list-1 and change the list-1 values as position indexes 0, 1, 2 to N-1
        int counter = 0;
        Node* head2 = new Node(head->val);
        head->val = counter++;
        Node* tmp1 = head->next;
        Node** tmp2_pptr = &(head2->next);
        while(tmp1)
        {
            *tmp2_pptr = new Node(tmp1->val);
            tmp2_pptr = &((*tmp2_pptr)->next);
            tmp1->val = counter++;
            tmp1 = tmp1->next;
        }
        
        // Pass 2/4: Using position index of list-1, create array which maps the index of random pointer. 
        //           Example: arr[x] = y : Node at position x has random pointer to node at position y.
        int* pos_index = new int[counter];
        counter = 0;
        tmp1 = head;
        while(tmp1)
        {
            if(tmp1->random)
                pos_index[counter] = tmp1->random->val;
            else
                pos_index[counter] = -1;

            counter++;
            tmp1 = tmp1->next;
        }

        // Pass 3/4: Create an array of Node address for list-2.
        Node** pos_addr = new Node*[counter];
        counter = 0;

        tmp1 = head;
        Node* tmp2 = head2;
        while(tmp2)
        {
            tmp1->val = tmp2->val;
            pos_addr[counter++] = tmp2;
            tmp2 = tmp2->next;
            tmp1 = tmp1->next;
        }

        // Pass 4/4: 
        counter = 0;
        tmp2 = head2;
        while(tmp2)
        {
            if(pos_index[counter] != -1)
            {
                tmp2->random =  pos_addr[pos_index[counter]];
            }
            tmp2 = tmp2->next;
            counter++;
        }

        delete [] pos_index;
        delete [] pos_addr;
        return head2;

    }
};


