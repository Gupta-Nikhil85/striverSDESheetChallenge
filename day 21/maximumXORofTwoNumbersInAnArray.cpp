struct Node{
    Node* Links[2];
    
    bool containsKey(int val){
        return Links[val]!=NULL;
    }
    
    Node* next(int val){
        return Links[val];
    }
    
    void put(int val, Node* n){
        Links[val]=n;
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root= new Node();
    }
    void insert(int num){
        Node* node= root;
        for(int i=31; i>=0; i--){
            int bit= (num>>i)&1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node=node->next(bit);
        }
    }
    
    int getMax(int num){
        Node* node= root;
        int ans=0;
        for(int i=31; i>=0; i--){
            int bit= (num>>i)&1;
            if(node->containsKey(1-bit)){
                ans= ans | (1<<i);
                node=node->next(1-bit);
            }
            else node=node->next(bit);
        }
        return ans;
    }
};



int maximumXor(vector<int> A)
{
    Trie root;
    for(auto i : A) root.insert(i);
    int ans=0;
    for(auto i : A) ans= max(ans, root.getMax(i));
    return ans;   
}