class Solution {
public:
bool dfs(unordered_map<int,vector<int>>&adj,int source,int destination,vector<bool>&vis){
    vis[source]=true;
    if(source==destination){
        return true;
    }

    bool reached=false;
    for(auto &next:adj[source]){
        if(!vis[next]){
            reached=reached || dfs(adj,next,destination,vis);
        }

    }
return reached;

}
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
        }
        int Q=queries.size();
        vector<bool>result(Q);
        for(int i=0;i<Q;i++){
            int u=queries[i][0];
            int v=queries[i][1];
            vector<bool>vis(n,false);
                result[i]=dfs(adj,u,v,vis);
        }
        return result;
    }
};