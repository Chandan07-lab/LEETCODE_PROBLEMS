class Solution {
public:
#define P pair<int,pair<int,int>>
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        result[0][0]=0;
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto cur=pq.top();
            pq.pop();
            int d=cur.first;
            int i=cur.second.first;
            int j=cur.second.second;
            for(auto &di:dir){
                int x=i+di[0];
                int y=j+di[1];

                if(x<0||x>=m||y<0||y>=n){
                    continue;
                }

                int wt=(grid[x][y]==1)?1:0;

                if(d+wt<result[x][y]){
                    result[x][y]=d+wt;
                    pq.push({d+wt,{x,y}});
                }

            }

        }
       return result[m-1][n-1];
        
    }
};