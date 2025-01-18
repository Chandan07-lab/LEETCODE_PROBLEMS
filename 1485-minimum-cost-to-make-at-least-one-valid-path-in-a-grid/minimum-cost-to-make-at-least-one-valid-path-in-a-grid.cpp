class Solution {
public:
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;

        pq.push({0,0,0});
        result[0][0]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int currcost=curr[0];
            int i=curr[1];
            int j=curr[2];
            if(result[i][j]<currcost){
                continue;
            }

            for(int diri=0;diri<=3;diri++){
                int i_=i+dir[diri][0];
                int j_=j+dir[diri][1];

                if(i_>=0 && j_>=0 && i_<m &&j_<n){
                    int griddir=grid[i][j];
                    int dircost=(griddir-1!=diri)?1:0;

                        int newcost=currcost+dircost;

                    if(newcost<result[i_][j_]){
                        result[i_][j_]=newcost;
                        pq.push({newcost,i_,j_});
                    }
                }
            }
        }
        return result[m-1][n-1];
    }
};