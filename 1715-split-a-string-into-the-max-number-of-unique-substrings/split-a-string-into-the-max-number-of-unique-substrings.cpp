class Solution {
public:
void solve(string& s,int idx,unordered_set<string>&st,int ccount,int &mcount){
    if(ccount+(s.length()-idx)<=mcount){
        return;
    }

    if(s.length()==idx){
        mcount=max(ccount,mcount);
    }
    for(int i=idx;i<s.length();i++){
        string sub=s.substr(idx,i-idx+1);
        if(st.find(sub)==st.end()){
            st.insert(sub);
            solve(s,i+1,st,ccount+1,mcount);
            st.erase(sub);
        }
    }
}
    int maxUniqueSplit(string s) {
        unordered_set<string>st;
        int mcount=0;
        int ccount=0;
        solve(s,0,st,ccount,mcount);
        return mcount;
    }
};