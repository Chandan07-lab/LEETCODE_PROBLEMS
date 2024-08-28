class Solution {
public:
//bfs
vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};
bool checksub(vector<vector<int>>&g1,vector<vector<int>>&g2,int i,int j){
    int m=g1.size();
    int n=g1[0].size();

    bool re= true;
    queue<pair<int,int>> q;
    q.push({i,j});
    g2[i][j]=-1;
    while(!q.empty()){
        auto[x,y]=q.front();
        q.pop();
        if(g1[x][y]!=1){
            re=false;
        }
        for(auto &d : dir ){
            int nx=x+d[0];
            int ny=y+d[1];
            if(nx>=0 && nx<m && ny>=0 && ny<n && g2[nx][ny]==1){
                g2[nx][ny]= -1;
                q.push({nx,ny});
            }
        }


    }
return re;
}

//dfs
// bool checksub(vector<vector<int>>&g1,vector<vector<int>>&g2,int i,int j){
//     if(i<0 || i>=g1.size() || j<0 || j >=g1[0].size()){
//         return true;
//     }
//     if(g2[i][j]!=1){
//         return true;
//     }
//     g2[i][j]=-1;

//     bool re= (g1[i][j]==1);

//     re = re & checksub(g1,g2,i+1,j);
//     re = re & checksub(g1,g2,i-1,j);
//     re = re & checksub(g1,g2,i,j+1);
//     re = re & checksub(g1,g2,i,j-1);

//     return re;
// }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int subisland=0;
        int m=grid1.size();
        int n=grid1[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && checksub(grid1,grid2,i,j)){
                    subisland++;
                }
            }
        }
        return subisland;
    }
};