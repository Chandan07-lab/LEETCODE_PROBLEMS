class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>indegree,outdegree;

        for(auto&edge:pairs){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            indegree[v]++;
            outdegree[u]++;
        }
        int startnode=pairs[0][0];

        for(auto&it:adj){
            int node=it.first;
            if(outdegree[node]-indegree[node]==1){
                startnode=node;
                break;
            }
        }
        vector<int>epath;
        stack<int>st;
        st.push(startnode);

        while(!st.empty()){
            int curr=st.top();
            if(!adj[curr].empty()){
                int ngbr=adj[curr].back();
                adj[curr].pop_back();
                st.push(ngbr);
            }else{
                epath.push_back(curr);
                st.pop();
            }
        }

        reverse(epath.begin(),epath.end());
        vector<vector<int>>re;
        for(int i=0;i<epath.size()-1;i++){
            re.push_back({epath[i],epath[i+1]});
        }
        return re;
    }
};