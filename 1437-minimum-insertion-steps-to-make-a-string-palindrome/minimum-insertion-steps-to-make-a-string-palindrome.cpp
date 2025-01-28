class Solution {
public:
int dp[501][501];
int solve(string &s,int i,int j){
    if(i>=j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s[i]==s[j]){
        return dp[i][j]=solve(s,i+1,j-1);
    }

    return dp[i][j]=min(1+solve(s,i,j-1),1+solve(s,i+1,j));
}
    int minInsertions(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1);
    }
};