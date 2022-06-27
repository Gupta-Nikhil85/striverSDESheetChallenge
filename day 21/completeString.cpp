struct Node{
    Node* Links[26];
    bool flag;
    
    bool containsKey(char ch){
        return Links[ch-'a'];
    }
    void addkey(char ch, Node* n){
        Links[ch-'a']=n;
    }
    Node* next(char ch){
        return Links[ch-'a'];
    }
    void markEnd(){
        flag=true;
    }
};



void insert(string word, Node* root){
    Node* node= root;
    for(auto ch : word){
        if(!node->containsKey(ch)){
            node->addkey(ch, new Node());
        }
        node=node->next(ch);
    }
    node->markEnd();
}
bool customsearchword(string word, Node* root){
    Node* node=root;
    for(auto ch : word){
        node=node->next(ch);
        if(!node->flag) return false;
    }
    return node->flag;
}



string completeString(int n, vector<string> &a){
    Node* root= new Node();
    for(auto s : a){
        insert(s, root);
    }
    int ans=0;
    string ansString="None";
    for(auto s: a){
        if(customsearchword(s, root)) {
            if(ans < s.length()){
                ansString=s;
                ans=s.length();
            }
            if(ans ==s.length()){
                ansString= ansString > s ? s : ansString;
            }
        }
    }
    return ansString;
}