class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();

        unordered_map<char,int>mp;
        for(auto ch:t){
            mp[ch]++;
        }
        int reqcount=t.length();
        int i=0,j=0;
        int minstart=0;
        int minwindow=INT_MAX;

        while(j<n){
            char ch=s[j];

            if(mp[ch]>0){
                reqcount--;
            }
            mp[ch]--;

            while(reqcount==0){
                if(minwindow>j-i+1){
                    minwindow=j-i+1;
                    minstart=i;
                }

                char ch_i=s[i];
                mp[ch_i]++;
                if(mp[ch_i]>0){
                    reqcount++;
                }
                i++;
            }
            j++;
        }
        
        return minwindow==INT_MAX? "":s.substr(minstart,minwindow);
    }
};