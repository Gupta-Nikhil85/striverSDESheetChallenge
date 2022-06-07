#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(second==NULL) return first;
    if(first==NULL) return second;
    Node<int> *h1=first, *h2=second;
    Node<int> *head= new Node<int>(-1);
    Node<int> *temp=head;
    while(h1!=NULL && h2!=NULL){
        if(h1->data < h2->data){
            head->next=h1;
            h1=h1->next;
            head=head->next;
        }else{
            head->next=h2;
            h2=h2->next;
            head=head->next;
        }
    }
    if(h1!=NULL) head->next=h1;
    if(h2!=NULL) head->next=h2;
    return temp->next;    
}
