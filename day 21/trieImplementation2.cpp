
struct Node{
    Node* links[26];
    int ew=0;
    int cp=0;
    
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void addKey(char ch, Node* nxt){
        links[ch-'a']=nxt;
    }
    Node* next(char ch){
        return links[ch-'a'];
    }
    void incrementCP(){
        cp++;
    }
    void incrementEW(){
        ew++;
    }
    void reduceCP(){
        cp--;
    }
    void reduceEW(){
        ew--;
    }
    
};

class Trie{

    private:
    Node* root;
    
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node* node= root;
        for(auto ch : word){
            if(!node->containsKey(ch)){
                node->addKey(ch, new Node());
            }
            node= node->next(ch);
            node->incrementCP();
        }
        node->incrementEW();
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(auto ch : word){
            if(!node->containsKey(ch)) return 0;
            node=node->next(ch);
        }
        return node->ew;        
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(auto ch : word){
            if(!node->containsKey(ch)) return 0;
            node=node->next(ch);
        }
        return node->cp; 
    }

    void erase(string &word){
        Node* node=root;
        for(auto ch: word){
            node=node->next(ch);
            node->reduceCP();
        }
        node->reduceEW();
    }
};
