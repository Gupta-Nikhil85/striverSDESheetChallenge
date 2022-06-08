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

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	// Write your code here.
    if(n==0 || head==NULL || head->next==NULL) return head;
    int cnt=b[0];
//     cout<<cnt<<" ";
    if(cnt==0){
        return getListAfterReverseOperation(head, n-1,b+1);
    }
    Node *temp=head, *prev=NULL;
    while(cnt>0 && temp!=NULL){
        Node* n= temp->next;
        temp->next=prev;
        prev=temp;
        temp=n;
        cnt--;
    }
    if(cnt>0) return prev;
    
    Node* newHead= getListAfterReverseOperation(temp, n-1,b+1);
    head->next=newHead;
    
    return prev;
}