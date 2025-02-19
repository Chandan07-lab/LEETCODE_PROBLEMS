class Solution {
public:
bool solve(int ind,vector<int>&nums,int k,vector<vector<int>>&dp){
    if(k==0){
        return true;
    }
    if(ind==0){
        return nums[0]==k;
    }

    if(dp[ind][k]!=-1){
        return dp[ind][k];
    }

    int nottaken=solve(ind-1,nums,k,dp);

    bool taken =false;
    if(nums[ind]<=k){
        taken=solve(ind-1,nums,k-nums[ind],dp);
    }

    return dp[ind][k]= taken || nottaken;

}
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        int k;
        if(sum%2){
            return false;
        }else{
             k=sum/2;
        }
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return solve(n-1,nums,k,dp);
    }
};