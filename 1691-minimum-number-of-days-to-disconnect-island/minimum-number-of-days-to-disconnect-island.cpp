class Solution {
public:
vector<vector<int>> dir{{-1,0},{1,0},{0,-1},{0,1}};
int m;
int n;
void dfs(vector<vector<int>>&grid,int i,int j,vector<vector<bool>>&vis){
    if(i<0 || i>=m || j<0 || j>=n || vis[i][j] ||grid[i][j]==0)
    return;

    vis[i][j]=1;
    for(auto& d:dir){
        int ni=i+d[0];
        int nj=j+d[1];
        dfs(grid,ni,nj,vis);
    }

}
int noi(vector<vector<int>>&grid){
    vector<vector<bool>> vis(m,vector<bool>(n));
    int is=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(!vis[i][j] && grid[i][j]==1){
                dfs(grid,i,j,vis);
                is++;
            }
        }
    }
    return is;
}
    int minDays(vector<vector<int>>& grid) {
m=grid.size();
n=grid[0].size();
int is=noi(grid);
if(is>1 || is==0){
    return 0;
}else{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
                is=noi(grid);
                grid[i][j]=1;
                if(is>1 || is==0)
                return 1;
            }
        }
    }
}
return 2;
    }
};