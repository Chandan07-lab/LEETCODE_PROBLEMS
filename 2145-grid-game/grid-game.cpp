class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long row1colsum=accumulate(grid[0].begin(),grid[0].end(),0LL);
        long long secondrowcolsum=0;

        long long minimizedrobot2=LONG_LONG_MAX;

        for(int i=0;i<grid[0].size();i++){
            row1colsum-=grid[0][i];

            long long robo1=max(row1colsum,secondrowcolsum);

            minimizedrobot2=min(minimizedrobot2,robo1);

            secondrowcolsum+=grid[1][i];
        } 
        
        return minimizedrobot2;
    }
};