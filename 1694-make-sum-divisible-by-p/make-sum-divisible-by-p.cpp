class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int n=nums.size();
       int sum=0;
       for(int num:nums){
        sum=(sum+num)%p;
       } 
       int tar=sum%p;
       if(tar==0){
        return 0;
       }
       unordered_map<int,int>mp;
       int curr=0;
       mp[0]=-1;
       int result=n;
       for(int j=0;j<n;j++){
        curr=(curr+nums[j])%p;
        int remain=(curr-tar+p)%p;
        if(mp.find(remain)!=mp.end()){
            result=min(result,j-mp[remain]);
        }

        mp[curr]=j;
       }
       return result==n?-1: result;
    }
};