class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int presum=0;
        int cnt=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
             presum+=nums[i];
            
            int remain=presum-k;

           cnt+=mp[remain];

           mp[presum]+=1;
        }
        
        return cnt;
    }
};