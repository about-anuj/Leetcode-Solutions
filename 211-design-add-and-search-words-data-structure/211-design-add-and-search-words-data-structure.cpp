class trie{
    public:
    trie* child[26]={NULL};
    bool count=0;
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    trie* root=new trie();
    bool check(string &s, int i,int n,trie* t)
    {
        if(!t) return false;
        if(i==n) return t->count;
        
        if(s[i]!='.')
            return check(s,i+1,n,t->child[s[i]-'a']);
        else{
            for(int j=0;j<26;j++)
                {
                if(check(s,i+1,n,t->child[j]))
                    return true;
                 }
            return false;
        }
    }
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        trie* t=root;
        for(auto i:word)
        {
            if(!t->child[i-'a'])
                t->child[i-'a']=new trie();
            t=t->child[i-'a'];
        }
        t->count=1;
    }
    
    bool search(string word) {
        //trie* t=root;
        return check(word,0,word.size(),root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */