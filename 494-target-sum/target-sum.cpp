class Solution {
public:
int solve(vector<int>& nums,int t,int i,vector<vector<int>>&dp){
    if(i==0){
        if(t==0 && nums[0]==0 ){
            return 2;
        }
        
        if(t==0 ||nums[0]==t){
            return 1;
        }

        return 0;
    }

        if(dp[i][t]!=-1){
            return dp[i][t];
        }
        int nottake=solve(nums,t,i-1,dp);

        int take=0;
    
    if(nums[i]<=t){
        take=solve(nums,t-nums[i],i-1,dp);
    }

    return dp[i][t]=take+nottake;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum-target<0||(sum-target)%2) return 0;

        int s2=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(s2+1,-1));
        return solve(nums,s2,n-1,dp);
    }
};