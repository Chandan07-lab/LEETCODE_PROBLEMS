class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        int n=s.length();
        vector<int>maxright(10,-1);

        for(int i=0;i<n;i++){
            int idx=s[i]-'0';
            maxright[idx]=i;
        }
        for(int i=0;i<n;i++){
            char currchar=s[i];
            int currdigit=currchar-'0';
            for(int dig=9;dig>currdigit;dig--){
                if(maxright[dig]>i){
                    swap(s[i],s[maxright[dig]]);
                    return stoi(s);
                }
            }
        }

        return num;
    }
};