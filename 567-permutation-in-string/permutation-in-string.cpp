class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m){
            return false;
        }
        vector<int>s1freq(26,0);
        vector<int>s2freq(26,0);
        for(int i=0;i<n;i++){
            s1freq[s1[i]-'a']++;
        }
        int i=0;
        int j=0;
        while(j<m){
            s2freq[s2[j]-'a']++;

            if(j-i+1>n){
                s2freq[s2[i]-'a']--;
                i++;
            }
            if(s1freq==s2freq){
                return true;
            }
            j++;
        }

        // string sorts1=s1;
        // sort(sorts1.begin(),sorts1.end());
        // for(int i=0;i<=m-n;i++){
        //     string temp=s2.substr(i,n);
        //     sort(temp.begin(),temp.end());
        //     if(temp==sorts1) return true;
        // }
         return false;
    }
};