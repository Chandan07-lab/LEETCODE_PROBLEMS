class Trie {
public:

    struct trienode{
        bool isendword;
        trienode *children[26];
    };

    trienode *getnode(){
        trienode* newnode= new trienode();
        newnode->isendword=false;

        for(int i=0;i<26;i++){
            newnode->children[i]=NULL;
        }

        return newnode;
    }

    trienode * root;

    Trie() {
        root=getnode();
    }
    
    void insert(string word) {
        trienode *crawl=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(crawl->children[ind]==NULL){
                crawl->children[ind]=getnode();
            }

            crawl=crawl->children[ind];
        }

        crawl->isendword=true;
    }
    
    bool search(string word) {
        trienode*crawl=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(crawl->children[ind]==NULL){
                return false;
            }
            crawl=crawl->children[ind];
        }

        return (crawl!=NULL && crawl->isendword);
    }
    
    bool startsWith(string prefix) {
        trienode*crawl=root;
        int i=0;

        for(i;i<prefix.length();i++){
            int ind=prefix[i]-'a';
            if(crawl->children[ind]==NULL){
                return false;
            }
            crawl=crawl->children[ind];
        }
        return (i==prefix.length());
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */