class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();

        vector<vector<int>>adj(v);
        queue<int>que;

        vector<int>indegre(v,0);

        for(int i=0;i<v;i++){
            for(int & a:graph[i]){
                adj[a].push_back(i);
                indegre[i]++;
            }
        }

        for(int i=0;i<v;i++){
            if(indegre[i]==0){
                que.push(i);
            }

        }

        vector<bool>safe(v,false);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            safe[u]=true;
            for(int &V:adj[u]){
                indegre[V]--;

                if(indegre[V]==0){
                    que.push(V);
                }
            }

        }
        vector<int>safenode;
        for(int i=0;i<v;i++){
            if(safe[i]){
                safenode.push_back(i);
            }
        }
        return safenode;
    }
};