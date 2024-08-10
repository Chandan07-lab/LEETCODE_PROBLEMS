class Solution {
public:
void noi(vector<vector<int>>& m,int i,int j){
    if( i<0|| i>=m.size()||j<0 || j>=m[0].size() ||m[i][j]==1){
        return;
    }
    m[i][j]=1;
    noi(m,i+1,j);
    noi(m,i-1,j);
    noi(m,i,j+1);
    noi(m,i,j-1);
}

    int regionsBySlashes(vector<string>& grid) {
        int rows= grid.size();
        int cols=grid[0].size();

        int r=0;
        vector<vector<int>>m(rows*3,vector<int>(cols*3,0));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='/'){
                    m[i*3][j*3+2]=1;
                    m[i*3+1][j*3+1]=1;
                    m[i*3+2][j*3]=1;
                }else if(grid[i][j]=='\\'){
                    m[i*3][j*3]=1;
                    m[i*3+1][j*3+1]=1;
                    m[i*3+2][j*3+2]=1;
                }
            }
        }
        for(int i=0;i<m.size();i++){
            for(int j=0;j<m[0].size();j++){
                if(m[i][j]==0){
                    noi(m,i,j);
                    r++;
                }
            }
        }
        return r;
    }
};