class Solution {
public:
int m;
int n;
vector<int>dir = {-1,0,1};
int dfs(int r,int c,vector<vector<int>>&g,vector<vector<int>>&t){
    if(t[r][c]!=-1){
        return t[r][c];
    }
    int moves=0;
    for(int &d:dir){
        int nrow=r+d;
        int ncol=c+1;
        if(nrow>=0 && nrow<m && ncol>=0 && ncol < n && g[nrow][ncol]>g[r][c]){
            moves=max(moves,1+dfs(nrow,ncol,g,t));
        }

    }
    return t[r][c]=moves;
}
    int maxMoves(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
       int r=0;
       vector<vector<int>>t(m,vector<int>(n,-1));
       for(int i=0;i<m;i++){
        r=max(r,dfs(i,0,grid,t));
       }
        return r;
    }
};