class Solution {
public:
    bool dfs(vector<int>&color,vector<vector<int>>& graph,int index,int col){
        color[index]=col;

        for(auto& v:graph[index]){

            if(color[v]==color[index]){
                return false;
            }

            if(color[v]==-1){
                int colc=1-col;
               if(dfs(color,graph,v,colc)==false){
                return false;
               }
            }

        }
        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
       
        vector<int>color(n,-1);

        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(color,graph,i,1)==false){
                    return false;
                }
            }
        }
        return true;
    }
};