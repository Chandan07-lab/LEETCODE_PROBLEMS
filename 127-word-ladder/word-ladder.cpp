class Solution {
public:

void pushadjacent(queue<string>&q,unordered_map<string,bool>&mp,string curr){
        int n= curr.length();
        for(int i=0;i<n;i++){
            char temp=curr[i];
            for(char ch='a';ch<='z';ch++){
                curr[i]=ch;
                if(mp.find(curr)!=mp.end() && mp[curr]==false){
                    mp[curr]=true;
                    q.push(curr);
                }
                curr[i]=temp;
            }
        }


}

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(wordList.size()==0){
            return 0;
        }

        unordered_map<string,bool>mp;
        for(auto& s:wordList){
            mp[s]=false;
        }
        
        if(mp.find(endWord)==mp.end()){
            return 0;
        }

        int level=1;
        queue<string>q;
        q.push(beginWord);

        while(!q.empty()){
            int n=q.size();
            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==endWord){
                    return level;
                }

                pushadjacent(q,mp,curr);
            }
            level++;
        }

    return 0;
    }
};