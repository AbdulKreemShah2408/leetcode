class WordDictionary {
      struct Node {
        Node* children[26];
        bool isEnd;
        Node(){
            isEnd=false;
            for(int i=0;i<26;i++){
                children[i]=nullptr;
            }
        }
    };
    Node* root;
    bool dfs(string &word,int index,Node* curr){
        if(curr==nullptr) return false;
        if(index==word.size()) return curr->isEnd;
        char ch=word[index];
        if(ch !='.'){
          return dfs(word,index+1,curr->children[ch-'a']);
        }else{
            for(int i=0;i<26;i++){
                if(curr->children[i] !=nullptr){
                    if(dfs(word,index+1,curr->children[i])){
                        return true;
                    }
                }
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new Node();
            }
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */