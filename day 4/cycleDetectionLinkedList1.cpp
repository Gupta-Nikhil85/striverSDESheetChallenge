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

bool detectCycle(Node *head)
{
	//	Write your code here
    if(head==NULL || head->next==NULL){
        return false;
    }
    Node *slow= head, *fast=head;
    fast=fast->next->next;
    while(fast!=NULL  && fast->next!=NULL && slow!=fast){
        slow=slow->next;
        fast=fast->next->next;
    }
    return (fast==NULL || fast->next==NULL) ? false : true;
}