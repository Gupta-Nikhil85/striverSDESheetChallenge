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



int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int len1=0, len2=0;
    Node* temp=firstHead;
    while(temp!=NULL){
        temp=temp->next;
        len1++;
    }
    temp=secondHead;
    while(temp!=NULL){
        temp=temp->next;
        len2++;
    }
    Node* h1=firstHead, *h2=secondHead;
    if(len1<len2){
        int t= len1;
        len1=len2;
        len2=t;
        h1=secondHead;
        h2=firstHead;
    }
    while(len2<len1 && h1!=NULL){
        h1=h1->next;
        len2++;
    }
    if(h1==NULL){
        return -1;
    }
    while(h1!=NULL && h2!=NULL){
        if(h1==h2) return h1->data;
        h1=h1->next;
        h2=h2->next;
    }
    return -1;    
}