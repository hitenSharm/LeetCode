class TrieNode {
public:
    int wc=0;
    TrieNode* child[26]={nullptr};
    TrieNode(){
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* r=root;
        for(int i=0;i<word.size();i++)
        {
            if(r->child[word[i]-'a'])
            {
                r=r->child[word[i]-'a'];
            }
            else
            {
                r->child[word[i]-'a']=new TrieNode();
                r=r->child[word[i]-'a'];
            }
        }
        r->wc++;
    }
    
    bool search(string word) {
        TrieNode* r=root;
        for(int i=0;i<word.size();i++)
        {
            if(r->child[word[i]-'a'])
            {
                r=r->child[word[i]-'a'];
            }
            else
            return false;
        }
        if(r->wc==0)return false;
        return true;
    }
    
    bool startsWith(string prefix) {
        TrieNode* r=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(r->child[prefix[i]-'a'])
            {
                r=r->child[prefix[i]-'a'];
            }
            else
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */