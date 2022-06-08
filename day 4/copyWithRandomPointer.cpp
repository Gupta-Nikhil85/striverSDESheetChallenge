#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

typedef LinkedListNode<int> Node;

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(head==NULL) return head;
    Node* temp= head;
    while(temp!=NULL){
        Node* n= new Node(temp->data);
        n->next=temp->next;
        temp->next=n;
        temp=temp->next->next;        
    }
    temp=head;
    while(temp!=NULL){
        if(temp->random!=NULL)
        temp->next->random= temp->random->next;
        temp=temp->next->next;
    }

    temp=head->next;
    Node* ans=temp;
    while(temp->next!=NULL){
        temp->next=temp->next->next;
        temp=temp->next;
    }

    return ans;
    
}
