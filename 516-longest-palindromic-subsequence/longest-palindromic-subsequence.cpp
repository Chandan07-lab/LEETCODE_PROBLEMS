class Solution {
public:
int dp[1001][1001];
int solve(int m,int n,string &s,string &t){
    if(m<0 ||n<0){
        return 0;
    }

    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(s[m]==t[n]){
        return dp[m][n]=1+solve(m-1,n-1,s,t);
    }

    return dp[m][n]=max(solve(m-1,n,s,t),solve(m,n-1,s,t));

}
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string t =s;
        reverse(t.begin(),t.end());
        memset(dp,-1,sizeof(dp));
        return solve(n-1,n-1,s,t);
        
    }
};