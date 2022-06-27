struct Node{
    Node* Links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return Links[ch-'a']!=NULL;
    }
    void addKey(char ch, Node* n){
        Links[ch-'a']=n;
    }
    Node* getKey(char ch){
        return Links[ch-'a'];
    }   
    void markEnd(){
        flag=true;
    }
};

void insert(Node* root, string word){
    Node* node= root;
    for(auto ch : word){
        if(!node->containsKey(ch)){
            node->addKey(ch, new Node());
        }
        node=node->getKey(ch);
    }
    node->markEnd();
}

bool search(Node* root, string word){
    Node* node= root;
    for(auto ch : word){
        if(!node->containsKey(ch)) return false;
        node=node->getKey(ch);
    }
    return node->flag;
}


int distinctSubstring(string &word) {
    Node* root= new Node();
    int ans=0;
    for(int i=0; i<word.length(); i++){
        for(int j=i; j<word.length(); j++){
            string cur= word.substr(i, j-i+1);
            if(!search(root, cur)){
                ans++;
                insert(root, cur);
            }
        }
    }
    return ans;
}


//Optimised

struct Node{
    Node* Links[26];
    bool flag=false;
    
    bool containsKey(char ch){
        return Links[ch-'a']!=NULL;
    }
    void addKey(char ch, Node* n){
        Links[ch-'a']=n;
    }
    Node* getKey(char ch){
        return Links[ch-'a'];
    }   
    void markEnd(){
        flag=true;
    }
};

int distinctSubstring(string &word) {
    Node* root= new Node();
    int ans=0;
    for(int i=0; i<word.length(); i++){
        Node* node= root;
        for(int j=i; j<word.length(); j++){
            char ch=word[j];
            if(!node->containsKey(ch)){
                ans++;
                node->addKey(ch, new Node());
            }
            node=node->getKey(ch);
        }
    }
    return ans;
}
