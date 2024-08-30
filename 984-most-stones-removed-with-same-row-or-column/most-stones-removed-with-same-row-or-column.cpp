// class Solution {
// public:
// int n;
// void dfs(vector<vector<int>>&stones,int ind,vector<bool>&vis){
// vis[ind]=true;
// for(int i=0;i<n;i++){
//     if(!vis[i]&&((stones[i][0]==stones[ind][0]) ||(stones[i][1]==stones[ind][1]))){
//         dfs(stones,i,vis);
//     }
// }
// }
//     int removeStones(vector<vector<int>>& stones) {
//          n=stones.size();
//         vector<bool> vis(n,false);
//         int count=0;
//         for(int i=0;i<n;i++){
//             if(vis[i]){
//                 continue;
//             }
//             dfs(stones,i,vis);
//             count++;
//         }
//     return n-count;
        
//     }
// };

class Solution {
public:
int n;
vector<int> parent;
vector<int> rank;

int find (int i){
    if(parent[i]!=i){
        parent[i]=find(parent[i]);
    }
    return parent[i];
}

void uni(int i,int j){
    int root_i=find(i);
    int root_j=find(j);

    if(root_i != root_j){
    if(rank[root_i]>rank[root_j]){
        parent[root_j]=root_i;
    }else if(rank[root_j]>rank[root_i]){
        parent[root_i]=root_j;
    }
    else{
        parent[root_j]=root_i;
    }

    }
}

int removeStones(vector<vector<int>>& stones){
    n=stones.size();
parent.resize(n);
rank.resize(n);
for(int i=0;i<n;i++){
    parent[i]=i;
    rank[i]=1;
}
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(stones[i][0]==stones[j][0] || stones[i][1] == stones[j][1]){
            uni(i,j);
        }
    }
}
int group=0;
for(int i=0;i<n;i++){
    if(parent[i]==i){
        group++;
    }
}
return n-group;
}

};








