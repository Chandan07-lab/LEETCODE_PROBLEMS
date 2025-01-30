class Solution {
public:
int dp[2001][2001];
int solve(string& s,string& p,int m,int n){
    if(m<0 && n<0){
        return true;
    }

    if(n<0){
        return false;
    }

    if(m<0){
        for(int i=0;i<=n;i++){
            if(p[i]!='*'){
                return false;
            }
        }
            return true;
    }

    if(dp[m][n]!=-1){
        return dp[m][n];
    }

    if(s[m]==p[n]||p[n]=='?'){
        return  dp[m][n]=solve(s,p,m-1,n-1);
    }

    if(p[n]=='*'){
        return dp[m][n]=solve(s,p,m-1,n) || solve(s,p,m,n-1);
    }

return dp[m][n]=false;
}
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,p,m-1,n-1);
        
    }
};