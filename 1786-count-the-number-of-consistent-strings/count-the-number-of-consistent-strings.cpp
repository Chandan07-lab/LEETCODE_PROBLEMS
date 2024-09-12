class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask =0;
        for(char &c:allowed){
            mask|=(1<<(c-'a'));
        }
        int count=0;
        for(string & word:words){
            bool present=true;
            for(char &c:word){
                if(((mask>>(c-'a')&1))==0){
                    present=false;
                    break;
                }

            }
            if(present){
                count++;
            }
        }
        return count;
    }
};