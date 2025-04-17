class Solution {
public:

int solve(int m,int n,int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat){
    if(i>=m || j>=n ||mat[i][j]==1 ) return 0;

    if(i==m-1 && j==n-1) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    return dp[i][j]=solve(m,n,i+1,j,dp,mat)+solve(m,n,i,j+1,dp,mat);
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return solve(m,n,0,0,dp,obstacleGrid);
    }
};