class Solution {
public:
int bfs(int n,unordered_map<int,vector<int>>adj){
    queue<int>q;
    q.push(0);
    vector<bool>vis(n,false);
    vis[0]=true;
    int level=0;
    while(!q.empty()){
        int qsize=q.size();
        while(qsize--){
            int node=q.front();
            q.pop();
            if(node==n-1){
                return level;
            }
            for(auto&ngbr:adj[node]){
                if(!vis[ngbr]){
                    q.push(ngbr);
                    vis[ngbr]=true;
                }
            }
        }
        level++;
    }
    return -1;
}
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        int k=queries.size();
        vector<int>result(k);
        for(int i=0;i<k;i++){
            adj[queries[i][0]].push_back(queries[i][1]);
            result[i]=bfs(n,adj);

        }
        return result;
    }
};