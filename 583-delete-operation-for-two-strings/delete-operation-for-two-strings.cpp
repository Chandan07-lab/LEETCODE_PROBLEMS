class Solution {
public:
int dp[501][501];
int solve(int m,int n,string w1,string w2){
    if(m==0 || n==0){
        return m+n;
    }

    if(dp[m][n]!=-1){
        return dp[m][n];
    }

    if(w1[m-1]==w2[n-1]){
        return dp[m][n]=solve(m-1,n-1,w1,w2);
    }

    return dp[m][n]=min(1+solve(m-1,n,w1,w2),(1+solve(m,n-1,w1,w2)));


}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        memset(dp,-1,sizeof(dp));
       return solve(m,n,word1,word2);
        
    }
};