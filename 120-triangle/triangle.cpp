class Solution {
public:
int solve(int n,int i,int j,vector<vector<int>>&tri,vector<vector<int>>&dp){

    if(i==n-1){
        return tri[i][j];
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }


    return dp[i][j]=tri[i][j]+min(solve(n,i+1,j,tri,dp),solve(n,i+1,j+1,tri,dp));
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(n,0,0,triangle,dp);
        
    }
};