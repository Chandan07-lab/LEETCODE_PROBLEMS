class Solution {
public:
    long long countVowels(string s) {
        int n=s.size();
        long long count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e' ||s[i]=='i' || s[i]=='o'||s[i]=='u'){
                count+=(long long)(n-i)*(i+1);    
            }
        }

      return count;      
    }
};