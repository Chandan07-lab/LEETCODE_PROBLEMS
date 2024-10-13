class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k= nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int maxe1=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],i,0});
            maxe1=max(maxe1,nums[i][0]);

        }
        vector<int>result={-1000000,1000000};
        while(!pq.empty()){
            vector<int>curr=pq.top();
            pq.pop();
            int mine1=curr[0];
            int listin=curr[1];
            int id=curr[2];
            if(maxe1-mine1<result[1]-result[0]){
                result[0]=mine1;
                result[1]=maxe1;
            }
            if(id+1<nums[listin].size()){
                int next=nums[listin][id+1];
                pq.push({next,listin,id+1});
                maxe1=max(maxe1,next);
            }else{
                break;
            }
        }

       return result;
        
    }
};