class Solution {
public:
typedef pair<double,int> p;
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int,vector<pair<int,double>>> adj;
        vector<double>re(n,0.0);

        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v =edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<p> pq;
        re[start]=1.0;
        pq.push({1.0,start});
    while(!pq.empty()){
        int curnode=pq.top().second;
        double curprob=pq.top().first;
        pq.pop();
        for (auto& e : adj[curnode]) {
                int nextNode = e.first;
                double nextProb = curprob * e.second;
                
                // If we found a higher probability path, update and push to the queue
                if (nextProb > re[nextNode]) {
                    re[nextNode] = nextProb;
                    pq.push({nextProb, nextNode});
                }
            }
        }
return re[end];
    }
};