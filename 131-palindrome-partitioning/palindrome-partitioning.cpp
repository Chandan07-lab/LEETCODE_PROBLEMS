class Solution {
public:
bool ispalindrome(string s,int l,int r){
    while(l<r){
        if(s[l]!=s[r])
        return false;

        l++;
        r--;
    }
    return true;
}
void solve(string &s,vector<vector<string>>&result,vector<string>&curr,int i){
    if(i==s.length()){
        result.push_back(curr);
        return;
    }
    for(int idx=i;idx<s.length();idx++){
        if(ispalindrome(s,i,idx)){
            curr.push_back(s.substr(i,idx-i+1));
            solve(s,result,curr,idx+1);
            curr.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>result;
        vector<string> curr;
         solve(s,result,curr,0);
        return result;
    }
};