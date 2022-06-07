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

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here.
    if(head==NULL) return head;

    if(k==0){
        return head;
    }
    LinkedListNode<int> *slow=head, *fast=head;
    int cnt=0;
    while(cnt<k && fast!=NULL){
        fast=fast->next;
        cnt++;
    }
    if(k==cnt && fast==NULL) return head->next;
    if(fast==NULL) return head;
    while(fast->next!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=slow->next->next;
    return head;
}