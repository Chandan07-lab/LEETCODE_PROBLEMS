class Solution {
public:
void dfs(int s,int n,vector<vector<int>>&con,vector<bool>&v){
    v[s]=true;
    vector<int> adj;
    for(int i=0;i<n;i++){
        int x=con[s][i];
        if(x==1)
        adj.push_back(i);
    }
    for(auto y:adj){
        if(!v[y])
        dfs(y,n,con,v);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool>vis(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,n,isConnected,vis);
            }
        }
        return count;
    }
};