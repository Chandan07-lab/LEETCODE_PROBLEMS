class Solution {
public:
int dp[1001][1001];
int solve(int m,int n,string& t1,string &t2){
    if(m<0 ||n<0){
        return 0;
    }

    if(dp[m][n]!=-1){
        return dp[m][n];
    }

    if(t1[m]==t2[n]){
        return dp[m][n]=1+solve(m-1,n-1,t1,t2);
    }

    return dp[m][n]=max(solve(m-1,n,t1,t2),solve(m,n-1,t1,t2));

}
    int longestCommonSubsequence(string text1, string text2) {
   int m=text1.size();
   int n=text2.size();
   memset(dp,-1,sizeof(dp));
   return solve(m-1,n-1,text1,text2);
    }
};