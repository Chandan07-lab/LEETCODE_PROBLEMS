class Solution {
public:
int solve(int amount,int i,vector<vector<int>>&dp,vector<int>&coins){
    if(i==0){
        return (amount%coins[i]==0);
    }

   if(dp[i][amount]!=-1){
    return dp[i][amount];
   } 

    int nottake=solve(amount,i-1,dp,coins);
    int take=0;

    if(coins[i]<=amount){
        take=solve(amount-coins[i],i,dp,coins);
    }

    return dp[i][amount]=take+nottake;
}

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(amount,n-1,dp,coins);
    }
};