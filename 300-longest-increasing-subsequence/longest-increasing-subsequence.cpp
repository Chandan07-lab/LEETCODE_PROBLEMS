class Solution {
public:
int n;
int dp[2501][2501];
int solve(vector<int>&nums,int prev,int curr){
    if(curr==n){
        return 0;
    }
    if(prev!=-1 && dp[prev][curr]!=-1){
        return dp[prev][curr];
    }

    int taken =0;
    if(prev==-1 || nums[curr]>nums[prev]){
        taken=1+solve(nums,curr,curr+1);
    }

  int not_taken=solve(nums,prev,curr+1);

  if(prev!=-1){
    dp[prev][curr]=max(taken,not_taken);
  }

return max(taken,not_taken);
}
    int lengthOfLIS(vector<int>& nums) {
         n= nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,-1,0);
        
    }
};