class Solution {
public:

bool checksub(vector<vector<int>>&g1,vector<vector<int>>&g2,int i,int j){
    if(i<0 || i>=g1.size() || j<0 || j >=g1[0].size()){
        return true;
    }
    if(g2[i][j]!=1){
        return true;
    }
    g2[i][j]=-1;

    bool re= (g1[i][j]==1);

    re = re & checksub(g1,g2,i+1,j);
    re = re & checksub(g1,g2,i-1,j);
    re = re & checksub(g1,g2,i,j+1);
    re = re & checksub(g1,g2,i,j-1);

    return re;
}
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