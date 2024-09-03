class Solution {
public:
    int getLucky(string s, int k) {
        string numeric="";
        for(char c: s){
            int num=(c-'a'+1);
            numeric+=to_string(num);
        }
        int sum=0;
        for(int i=0;i<k;i++){
            sum=0;
            for(char dig:numeric){
                sum+=(dig-'0');
            }
            numeric=to_string(sum);
        }
return sum;
    }
};