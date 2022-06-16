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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    
    int carry=0;
    Node* head= new Node(-1);
    Node* n=head;
    while(head1!=NULL || head2!=NULL || carry!=0){
        int sum=carry;
        if(head1!=NULL){
            sum+=head1->data;
            head1=head1->next;
        }
        if(head2!=NULL){
            sum+=head2->data;
            head2=head2->next;
        }
        carry=sum/10;
        int dig=sum%10;
        n->next=new Node(dig);
        n=n->next;
    }
    return head->next;
    
    
    // Write your code here.
}