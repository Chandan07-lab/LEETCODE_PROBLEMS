class Solution {
public:
bool topocheck(unordered_map<int,vector<int>>adj,vector<int>indegree,int n){
    queue<int>que;
    int count=0;

    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            count++;
            que.push(i);
        }
    }
    while(!que.empty()){
        int f=que.front();
        que.pop();
        for(auto&v:adj[f]){
            indegree[v]--;
            if(indegree[v]==0){
                count++;
                que.push(v);
            }
        }
    }
    if(count==n){
        return true;
    }else{
        return false;
    }

}

    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>>adj;
        vector<int>indegree(numCourses,0);

        for(auto& vec: pre ){
            int a=vec[0];
            int b=vec[1];
            indegree[a]++;
            adj[b].push_back(a);
        
        }
        return topocheck(adj,indegree,numCourses);
    }
};