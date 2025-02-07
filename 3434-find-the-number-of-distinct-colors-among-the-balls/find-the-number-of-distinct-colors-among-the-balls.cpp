class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n=queries.size();
        vector<int>result(n);
        unordered_map<int,int>ballmap;
        unordered_map<int,int>colormap;

        for(int i=0;i<n;i++){
            int ballno=queries[i][0];
            int ballcolor=queries[i][1];

            if(ballmap.count(ballno)){
                int prevcol=ballmap[ballno];
                colormap[prevcol]--;
                
                if(colormap[prevcol]==0){
                    colormap.erase(prevcol);
                }
            }
            ballmap[ballno]=ballcolor;
            colormap[ballcolor]++;
            result[i]=colormap.size();
        }
        return result;
    }
};