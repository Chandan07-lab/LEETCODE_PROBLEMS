class Solution {
public:
void marked(int i,int j,vector<vector<int>>&grid){
    for(int row =i-1;row>=0;row--){
        if(grid[row][j]==2||grid[row][j]==3){
            break;
        }
        grid[row][j]=1;
    }
    for(int row=i+1;row<grid.size();row++){
        if(grid[row][j]==2||grid[row][j]==3){
            break;
        }
        grid[row][j]=1;
    }
    for(int col =j-1;col>=0;col--){
        if(grid[i][col]==2||grid[i][col]==3){
            break;
        }
        grid[i][col]=1;
    }
    for(int col =j+1;col<grid[0].size();col++){
        if(grid[i][col]==2||grid[i][col]==3){
            break;
        }
        grid[i][col]=1;
    }


}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));

        for(auto&guard:guards){
            int i=guard[0];
            int j=guard[1];
            grid[i][j]=3;
        }
        for(auto&wall:walls){
            int i=wall[0];
            int j=wall[1];
            grid[i][j]=2;
        }
        for(auto& check:guards){
            int i=check[0];
            int j=check[1];
            marked(i,j,grid);
        }
        int count=0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }
return count;
        
    }
};