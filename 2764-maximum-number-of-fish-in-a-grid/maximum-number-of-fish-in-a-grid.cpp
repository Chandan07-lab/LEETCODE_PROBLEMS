class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
int m,n;

int dfs(vector<vector<int>>&grid,int i,int j){
  
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
        return 0;
    }
    int totalfish = grid[i][j];
    grid[i][j]=0;
    for(auto&d : dir){
        int i_=i+d[0];
        int j_=j+d[1];
        totalfish+=dfs(grid,i_,j_);
    }
    return totalfish;
}
    int findMaxFish(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        int maxfish=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>=1){
                      maxfish=max(maxfish,dfs(grid,i,j)); 
                }
            }
        }
        return maxfish;
    }
};