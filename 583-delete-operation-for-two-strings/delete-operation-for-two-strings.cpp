class Solution {
public:
int dp[501][501];
int m,n;
int solve(int i,int j,string w1,string w2){
    if(i==m){
        return n-j; 
    }

    if(j==n){
        return m-i;
    }


    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(w1[i]==w2[j]){
        return dp[i][j]=solve(i+1,j+1,w1,w2);
    }

    return dp[i][j]=min(1+solve(i+1,j,w1,w2),(1+solve(i,j+1,w1,w2)));


}
    int minDistance(string word1, string word2) {
         m=word1.size();
         n=word2.size();
        memset(dp,-1,sizeof(dp));
       return solve(0,0,word1,word2);
        
    }
};