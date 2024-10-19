class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        //  string ans="";
        // sort(v.begin(),v.end());
        // int n=v.size();
        // string first=v[0],last=v[n-1];
        // for(int i=0;i<min(first.size(),last.size());i++){
        //     if(first[i]!=last[i]){
        //         return ans;
        //     }
        //     ans+=first[i];
        // }
        // return ans;
        
        string ans ="";
        bool mark= true;
        for(int i =0;i<v[0].size();i++){
            char c = v[0][i];
            for(int j=0;j<v.size();j++){
                if(c!=v[j][i]){
                    mark = false;
                    break;
                }
                else{
                    mark=true;
                }
            }
            if(mark){
                ans+=c;
            }
            else{
                break;
            }
        }
        return ans;
    }
};