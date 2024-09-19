class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int>result;

        for(int i=0;i<s.length();i++){
            if(s[i]=='+'||s[i]=='-'||s[i]=='*'){
                vector<int>lres=diffWaysToCompute(s.substr(0,i));
                vector<int>rres=diffWaysToCompute(s.substr(i+1));
                for(int &x:lres){
                    for(int &y:rres){
                        if(s[i]=='+'){
                            result.push_back(x+y);
                        }else if(s[i]=='-'){
                            result.push_back(x-y);
                        }else{
                            result.push_back(x*y);
                        }

                    }
                }

            }
        }
        if(result.empty()){
            result.push_back(stoi(s));
        }

        return result;
        
    }
};