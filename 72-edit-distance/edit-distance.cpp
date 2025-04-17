class Solution {
public:
int solve(int i,int j,vector<vector<int>>&dp,int m,int n,string w1,string w2){
    if(i<0){
        return j+1;
    }
    if(j<0){
        return i+1;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(w1[i]==w2[j]){
        return dp[i][j]=solve(i-1,j-1,dp,m,n,w1,w2);
    }

    return dp[i][j]=1+min({solve(i-1,j-1,dp,m,n,w1,w2),solve(i-1,j,dp,m,n,w1,w2),solve(i,j-1,dp,m,n,w1,w2)});
}
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,dp,m,n,word1,word2);
        
    }
};