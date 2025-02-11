class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=part.length();
        string result="";
        for(char &ch: s){
            result.push_back(ch);
            if(result.length()>=n && result.substr(result.length()-n)==part){
                result.erase(result.length()-n);
            }

        }
        return result;
    }
};