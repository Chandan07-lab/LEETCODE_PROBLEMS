#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    typedef pair<long long,int> pli;  

    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto &t : roads){
            adj[t[0]].push_back({t[1], t[2]});
            adj[t[1]].push_back({t[0], t[2]});
        }

        
        priority_queue<pli, vector<pli>, greater<pli>> pq;
        
        
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        int mod = 1e9 + 7;
        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();
            
           
            if(d > dist[node])
                continue;

           
            for(auto &edge : adj[node]){
                int nextNode = edge.first;   
                int weight = edge.second;
                
               
                if(d + weight < dist[nextNode]){
                    dist[nextNode] = d + weight;
                    pq.push({dist[nextNode], nextNode});
                    ways[nextNode] = ways[node];  
                }
                
                else if(d + weight == dist[nextNode]){
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
