class Solution {
public:
#define P pair<int,pair<int,int>>
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<P,vector<P>,greater<P>>pq;
        if(grid[0][1]>1 && grid[1][0]>1){
            return -1;
        }
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        pq.push({grid[0][0],{0,0}});
        result[0][0]=0;
        while(!pq.empty()){
            int time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            if(row==m-1 &&col==n-1){
                return result[m-1][n-1];
            }
            if(vis[row][col]){
                continue;
            }

            vis[row][col]=true;

            for(auto&d:dir){
                int r=row+d[0];
                int c=col+d[1];

                if(r<0 ||r>=m|| c<0 ||c>=n){
                    continue;
                }

                if(grid[r][c]<=time+1){
                    pq.push({time+1,{r,c}});
                    result[r][c]=time+1;
                }else if((grid[r][c]-time)%2==0){
                    pq.push({grid[r][c]+1,{r,c}});
                    result[r][c]=grid[r][c]+1;               
                     }else{
                        pq.push({grid[r][c],{r,c}});
                        result[r][c]=grid[r][c];
                }
            }
        }

        return -1;
        
    }
};