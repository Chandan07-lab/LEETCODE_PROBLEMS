class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int mask=0;
        mp[mask]=-1;
        int maxl=0;
        for(int i=0;i<s.length();i++){
            int val=0;
            if(s[i]=='a') val=(1<<0);
            else if(s[i]=='e') val=(1<<1);
            else if(s[i]=='i') val=(1<<2);
            else if(s[i]=='o') val=(1<<3);
            else if(s[i]=='u') val=(1<<4);

            mask=mask^val;

            if(!mp.count(mask)){
                mp[mask]=i;
            }
            maxl=max(maxl,i-mp[mask]);
        }
        return maxl;
    }
};