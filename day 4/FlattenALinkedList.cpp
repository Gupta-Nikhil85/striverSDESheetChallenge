#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
// Node* merge(Node* h1, Node* h2){
//     if(h1==NULL) return h2;
//     if(h2==NULL) return h1;
//     if(h1->data>h2->data){
//         h2->child=merge(h1, h2->child);
//         return h2;
//     }
//     h1->child=merge(h1->child, h2);
//     return h1;
// }

Node* merge(Node* h1 , Node* h2){
    if(h1==NULL) return h2;
    if(h2==NULL) return h1;
    Node* head= new Node(-1);
    Node* temp=head;
    while(h1!=NULL && h2!=NULL){
        if(h1->data < h2->data){
            temp->child=h1;
            temp=temp->child;
            h1=h1->child;
        }
        else{
            temp->child=h2;
            temp=temp->child;
            h2=h2->child;
        }
    }
    if(h1!=NULL) temp->child=h1;
    if(h2!=NULL) temp->child=h2;
    return head->child;
}


Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    if(head==NULL || head->next==NULL) return head;
    return merge(head, flattenLinkedList(head->next));
    
}
