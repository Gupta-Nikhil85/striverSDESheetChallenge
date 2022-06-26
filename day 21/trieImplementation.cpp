/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
struct Node{
    Node* links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void addKey(char ch, Node* temp){
        links[ch-'a']=temp;
    }
    Node* next(char ch){
        return links[ch-'a'];
    }
    void markEnd(){
        flag=true;
    }
    
};

class Trie {

private:
    Node* root;
    
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node=root;
        for(auto ch : word){
            if(!node->containsKey(ch)){
                node->addKey(ch,new Node());
            }
            node=node->next(ch);
        }
        node->markEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node= root;
        for(auto ch : word){
            if(!node->containsKey(ch)) return false;
            node=node->next(ch);
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node= root;
        for(auto ch : prefix){
            if(!node->containsKey(ch)) return false;
            node=node->next(ch);
        }
        return true;
    }
};