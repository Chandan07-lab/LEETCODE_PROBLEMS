class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        int i=0;
        int j=0;

        while(i<n){
            if(isdigit(s[i])){
                j=max(j-1,0);

            }else{
                s[j]=s[i];
                j++;
            }
            i++;
        }
        
        s.resize(j);
        return s;
    }
};