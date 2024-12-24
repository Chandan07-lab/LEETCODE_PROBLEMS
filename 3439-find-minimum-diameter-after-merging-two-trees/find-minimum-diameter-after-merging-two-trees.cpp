class Solution {
public:

pair<int,int>bfs(unordered_map<int,vector<int>>&adj,int source){
    queue<int>que;
    que.push(source);
    unordered_map<int,bool>vis;
    vis[source]=true;
    int distance=0;
    int farthest=0;
    while(!que.empty()){
        int size=que.size();

        while(size--){
            int curr=que.front();
            que.pop();
            farthest=curr;
            for(auto &ngbr:adj[curr]){
                if(vis[ngbr]==false){
                    vis[ngbr]=true;
                    que.push(ngbr);
                }
            }
        }
        if(!que.empty()){
            distance++;
        }
    }
return {farthest,distance};
}

int fdia(unordered_map<int,vector<int>>adj){
    auto[far,dist]=bfs(adj,0);

    auto[other,diam]=bfs(adj,far);

    return diam;
}


unordered_map<int,vector<int>>badj(vector<vector<int>>&edge){
    unordered_map<int,vector<int>>adj;
    for(auto&ed:edge){
        int u=ed[0];
        int v=ed[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
return adj;
}
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        unordered_map<int,vector<int>>adj1=badj(edges1);
        unordered_map<int,vector<int>>adj2=badj(edges2);

        int d1=fdia(adj1);
        int d2=fdia(adj2);

        int combined=(d1+1)/2+(d2+1)/2+1;
        
        return max({d1,d2,combined});
    }
};