class Solution {
public:
void solve(string&curr,vector<string>&result,int open,int close,int n){
    if(curr.length()==2*n){
        result.push_back(curr);
        return ;
    }

    if(open<n){
        curr.push_back('(');
        solve(curr,result,open+1,close,n);
        curr.pop_back();
    }
    if(close<open){
        curr.push_back(')');
        solve(curr,result,open,close+1,n);
        curr.pop_back();
    }

}
    vector<string> generateParenthesis(int n) {
        int open =0, close=0;
        string curr="";
        vector<string>result;
     solve(curr,result,open,close,n);
    return result;    
    }
};