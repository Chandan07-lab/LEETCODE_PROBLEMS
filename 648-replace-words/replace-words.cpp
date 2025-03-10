class Solution {
public:
    struct trienode {
        trienode* children[26];
        bool isendofword;
    };

    trienode*
    getnode() {
        trienode* newnode = new trienode();
        newnode->isendofword = false;

        for (int i = 0; i < 26; i++) {
            newnode->children[i] = NULL;
        }
        return newnode;
    }

    trienode* root;

    void insert(string word) {
        trienode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';
            if (!crawler->children[index]) {
                crawler->children[index] = getnode();
            }

            crawler = crawler->children[index];
        }

        crawler->isendofword = true;
    }

    string search(string word){
        trienode * crawler=root;
        for(int i=0;i<word.length();i++){
            int ind=word[i]-'a';
            if(!crawler->children[ind]){
                return word;
            }

            crawler=crawler->children[ind];

            if(crawler->isendofword){
                return word.substr(0,i+1);
            }
        }
return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
            stringstream ss(sentence);
            string word;
            string result;

            root=getnode();

            for(auto s:dictionary){
                insert(s);
            }
        
        while(getline(ss,word,' ')){
            result+=search(word)+" ";
        }

        result.pop_back();

        return result;
    }
};