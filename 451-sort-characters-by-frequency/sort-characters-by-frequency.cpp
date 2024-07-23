class Solution {
public:
typedef pair<char,int> p;

    string frequencySort(string s) {
        vector<p> vec(123);
        for(char &ch: s){
            int f=vec[ch].second;
            vec[ch]={ch,f+1};
        }
        sort(vec.begin(),vec.end(),[&](p &p1,p &p2){
            return p1.second>p2.second;
        });
        string r="";
        for(int i=0;i<122;i++){
            r+=string(vec[i].second,vec[i].first);
        }
        return r;
    }
};