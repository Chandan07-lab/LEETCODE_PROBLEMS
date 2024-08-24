class Solution {
public:
    int coinChangeHelper(vector<int>& coins, int amount,int dp[10006]) {
        if (amount == 0)
            return 0;
        if(dp[amount] !=-1) return dp[amount];
        int ans = INT_MAX;
        for (int coin : coins) {
            if (amount - coin >= 0)
                ans = min(ans + 0LL, coinChangeHelper(coins, amount - coin,dp) + 1LL);
        }

        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) { 
        int dp[10006];
        memset(dp,-1,sizeof(dp));
        int ans =  coinChangeHelper(coins, amount,dp); 
        return ans == INT_MAX? -1: ans;
    }
};