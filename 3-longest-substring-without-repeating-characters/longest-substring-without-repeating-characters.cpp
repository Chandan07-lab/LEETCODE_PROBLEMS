class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int res=0;

        int i=0,j=0;
        unordered_map<char,int>mp;

        while(j<n){
            char ch=s[j];
            if(mp.count(ch)){
                i=max(i,mp[ch]+1);
            }

            mp[ch]=j;
            res=max(res,j-i+1);
            j++;
        }
        
        return res;
    }
};