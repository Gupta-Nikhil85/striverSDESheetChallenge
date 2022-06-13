#include <bits/stdc++.h>

class Node{
public:
    Node* prev;
    Node* next;
    int key;
    int value;
    
    Node(int key, int value){
        this->key=key;
        this->value=value;
        this->prev=NULL;
        this->next=NULL;
    }
};

class LRUCache
{
    unordered_map<int, Node*> m;
    int capacity;
    Node *head; //LRU at tail
    Node *tail;
public:
    LRUCache(int capacity)
    {
        this->capacity=capacity;
    }

    int get(int key)
    {
        if(m.find(key)==m.end()){
            return -1;
        }
        Node* root=m[key];
        if(root==head){
            return root->value;
        }
        root->prev->next=root->next;
        if(root->next!=NULL) root->next->prev=root->prev;
        else tail=root->prev;
        root->prev=NULL;
        root->next=head;
        head->prev=root;
        head=root;
        return root->value;
    }

    void put(int key, int value)
    {
        if(m.find(key)==m.end()){
            Node* root= new Node(key, value);
            m[key]=root;
            if(m.size()==1){
                head=root;
                tail=root;
                return;
            }
            root->next=head;
            head->prev=root;
            head=root;
            if(m.size()>capacity){
                m.erase(tail->key);
                tail=tail->prev;
                tail->next=NULL;
            }
            return;
        }
        else{
            Node* root=m[key];
            if(root==head){
                root->value=value;
                return;
            }
            root->prev->next=root->next;
            if(root->next!=NULL) root->next->prev=root->prev;
            else tail=root->prev;
            root->prev=NULL;
            root->next=head;
            head->prev=root;
            root->value=value;
            head=root;
            m[key]=root;
            return;
        }
    }
};
