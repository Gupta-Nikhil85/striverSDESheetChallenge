#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *firstNode(Node *head)
{
	//    Write your code here.
    if(head==NULL || head->next==NULL) return NULL;
    
    Node *slow=head, *fast=head;
    fast=fast->next->next;
    slow=slow->next;
    while(slow!=fast && fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    if(fast==NULL || fast->next==NULL){
        return NULL;
    }
    slow=head;
    while(slow!=fast){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;    
}