#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
typedef LinkedListNode<int> Node;

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL || head->next==NULL) return true;
    Node* slow=head;
    Node* fast=head;
    Node* prev=NULL;
    Node* n= slow->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        n=slow->next;
        slow->next=prev;
        prev=slow;
        slow=n;
    }
    if(fast!=NULL) {
        slow=slow->next;
    }
    
    while(slow!=NULL && prev!=NULL){
        if(prev->data!=slow->data){
            return false;        
        }
        slow=slow->next;
        prev=prev->next;
    }
    return true;
}