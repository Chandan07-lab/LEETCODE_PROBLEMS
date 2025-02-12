class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        vector<int>result(n+1,INT_MAX);
        for(auto &vec:times){
            int u=vec[0];
            int v=vec[1];
            int wt=vec[2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        result[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(d>result[node]){
                continue;
            }

            for(auto&t:adj[node]){
                int dis=t.second;
                int adjnode=t.first;
                if(d+dis<result[adjnode]){
                    result[adjnode]=d+dis;
                    pq.push({d+dis,adjnode});
                }
            }
        }
        int maxDelay = 0;
        for (int i = 1; i <= n; i++) { 
            if(result[i] == INT_MAX)
                return -1;
            maxDelay = max(maxDelay, result[i]);
        }
        return maxDelay;
    }
};