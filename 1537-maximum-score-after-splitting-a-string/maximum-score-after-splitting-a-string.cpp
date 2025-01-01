class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int re=INT_MIN;

        int zero=0;
        int one=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                one++;
            }else{
                zero++;
            }
            re=max(re,zero-one);
        }
            if(s[n-1]=='1'){
                one++;
            }
        return  re+one;
        
    }
};