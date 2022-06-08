#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) {
    if(!head || !head->next) return head;
    
    Node* temp=head;
//     cout<<k<<endl;
    int len=1;
    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }
    k%=len;
    k=len-k;
    temp->next=head;
    Node *prev=temp;
    while(k>0){
        prev=prev->next;
        head=head->next;
        k--;
    }
    prev->next=NULL;
    return head;
    
}