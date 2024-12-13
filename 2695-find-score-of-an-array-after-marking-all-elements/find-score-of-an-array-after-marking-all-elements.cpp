class Solution {
public:
#define P pair<int,int>
    long long findScore(vector<int>& nums) {
        int n= nums.size();
        vector<bool>vis(n,false);

        priority_queue<P,vector<P>,greater<P>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }

        long long score=0;

        while(!pq.empty()){
            auto temp=pq.top();
            int el=temp.first;
            int ind=temp.second;
            pq.pop();

            if(!vis[ind]){
                vis[ind]=true;
                score+=el;

                if(ind-1>=0 && !vis[ind-1]){
                    vis[ind-1]=true;
                  }

                 if(ind+1<n && !vis[ind+1]){
                    vis[ind+1]=true;
                 } 

            }
   }


return score;          
    }
};