class Solution {
public:
#define P pair<int,int>
// int bfs(int n,unordered_map<int,vector<int>>adj){
//     queue<int>q;
//     q.push(0);
//     vector<bool>vis(n,false);
//     vis[0]=true;
//     int level=0;
//     while(!q.empty()){
//         int qsize=q.size();
//         while(qsize--){
//             int node=q.front();
//             q.pop();
//             if(node==n-1){
//                 return level;
//             }
//             for(auto&ngbr:adj[node]){
//                 if(!vis[ngbr]){
//                     q.push(ngbr);
//                     vis[ngbr]=true;
//                 }
//             }
//         }
//         level++;
//     }
//     return -1;
// }
//     vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
//         unordered_map<int,vector<int>>adj;
//         for(int i=0;i<n-1;i++){
//             adj[i].push_back(i+1);
//         }
//         int k=queries.size();
//         vector<int>result(k);
//         for(int i=0;i<k;i++){
//             adj[queries[i][0]].push_back(queries[i][1]);
//             result[i]=bfs(n,adj);

//         }
//         return result;
//     }
int dij(int n,unordered_map<int,vector<P>>adj){
    vector<int>result(n,INT_MAX);
    result[0]=0;
    priority_queue<P,vector<P>,greater<P>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(node==n-1){
            return result[n-1];
        }

        if(d>result[node])
        continue;


        for(P &p:adj[node]){
            int adjnode=p.first;
            int dist=p.second;
            if(d+dist<result[adjnode]){
                result[adjnode]=d+dist;
                pq.push({d+dist,adjnode});
            }

        }
    }
    return result[n-1];
}


vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries){
unordered_map<int,vector<P>>adj;
vector<int>re;

for(int i=0;i<n-1;i++){
    adj[i].push_back({i+1,1});
}
for(auto &query:queries){
    int u=query[0];
    int v=query[1];
    adj[u].push_back({v,1});
    int d=dij(n,adj);
    re.push_back(d);

}
return re;
}
 };



















