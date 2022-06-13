#include<bits/stdc++.h>

class Node{
public:
    int key,value, cnt;
    Node* prev, *next;
    Node(int key, int value){
        this->value=value;
        this->key=key;
        this->cnt=1;
    }
};

class List{
public:
    Node* head;
    Node* tail;
    int size;
    
    List(){
        head= new Node(0,0);
        tail= new Node(0,0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    
    void addNode(Node* root){
        root->next=head->next;
        root->prev=head;
        head->next->prev=root;
        head->next=root;
        size++;
        return;
    }
    
    void deleteNode(Node* root){
        root->prev->next=root->next;
        root->next->prev=root->prev;
        size--;
        return;
    }    
};


class LFUCache
{
public:
    int cap;
    int minfreq;
    int cursize;
    unordered_map<int, Node*> lru; //key, key description
    map<int, List*> lfu; //freq, List
    LFUCache(int capacity)
    {
        // Write your code here.
        cap=capacity;
        cursize=0;
        minfreq=0;
    }
    
    void updateFreqMap(Node* root){
        int freq=root->cnt;
        lfu[freq]->deleteNode(root);
        if(root->cnt==minfreq && lfu[freq]->size==0){
            minfreq++;
        }
        List* newlist= new List();
        if(lfu.find(freq+1)!=lfu.end()){
            newlist=lfu[freq+1];
        }
        root->cnt++;
        newlist->addNode(root);
        lfu[freq+1]=newlist;      
    }

    int get(int key)
    {
        if(lru.find(key)!=lru.end()){
            Node* root=lru[key];
            updateFreqMap(root);
            return root->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(cap==0) return;
        
        if(lru.find(key)!=lru.end()){
            Node* root=lru[key];
            root->value=value;
            updateFreqMap(root);
            return;
        }
        else{
            if(cap==cursize){
                List* list= lfu[minfreq];
                lru.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            Node* n= new Node(key, value);
            List* list= new List();
            if(lfu.find(minfreq)!=lfu.end()) list=lfu[minfreq];
            list->addNode(n);
            lru[key]=n;
            lfu[minfreq]=list;
        }
    }
};
