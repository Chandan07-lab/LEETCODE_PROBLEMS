class Solution {
public:
int t[51];
int solve(int idx,string& s,int n,unordered_set<string>&st){
    if(idx>=n){
        return 0;
    }
    if(t[idx]!=-1){
        return t[idx];
    }
    string currstr="";
    int minextra=n;
    for(int i=idx;i<n;i++){
        currstr.push_back(s[i]);
        int currextra=(st.find(currstr)==st.end())?currstr.length():0;
        int nextextra=solve(i+1,s,n,st);
        int totalextra=currextra+nextextra;
        minextra=min(minextra,totalextra);

    }
    return t[idx]=minextra;
}
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.length();
        memset(t,-1,sizeof(t));
        unordered_set<string>st(dict.begin(),dict.end());
        return solve(0,s,n,st);
        
    }
};