#include <bits/stdc++.h>
static bool comp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

struct Node{
    Node* Links[2];
    
    bool containsKey(int bit){
        return (Links[bit]!=NULL);
    }
    void addKey(int bit, Node* node){
        Links[bit]=node;
    }
    Node* getNode(int bit){
        return Links[bit];
    }
};

void insert(Node* root, int num){
    Node* node= root;
    for(int i=31; i>=0; i--){
        int bit= (num>>i)&1;
        if(!node->containsKey(bit)){
            node->addKey(bit, new Node());
        }
        node= node->getNode(bit);
    }
}

int getMax(int num, Node* root){
    Node* node= root;
    int ans=0;
    for(int i=31; i>=0; i--){
        int bit= (num>>i)&1;
        if(node->containsKey(1-bit)){
            ans= ans | (1<<i);
            node=node->getNode(1-bit);
        }else{
            node=node->getNode(bit);
        }
    }
    return ans;
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    for(int i=0; i<queries.size(); i++){
        queries[i].push_back(i);
    }
    sort(queries.begin(), queries.end(), comp);
    sort(arr.begin(), arr.end());

    vector<int> ans(queries.size(),-1);
    Node* root= new Node();
    int cur=0;
    for(int i=0; i<queries.size(); i++){
        if(queries[i][1] < arr[0]) continue;
        
        while(cur < arr.size() && arr[cur] <= queries[i][1]){
            insert(root, arr[cur]);
            cur++;
        }
        ans[queries[i][2]]=getMax(queries[i][0], root);
    }
    return ans;
}