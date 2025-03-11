class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mp;
        for(auto str:s){
            mp[str]++;
        }

        for(auto str:t){
            mp[str]--;
        }

        for(auto st:mp){
            if(st.second!=0){
                return false;
            }
        }
        
        return true;
    }
};