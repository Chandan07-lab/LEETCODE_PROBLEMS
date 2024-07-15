class Solution {
public:

    int change(int amount, vector<int>& coins) {
       vector<int> dp(amount + 1, 0);
    dp[0] = 1; // There's one way to make amount 0

    // Iterate over each coin
    for (int coin : coins) {
        // Update the dp array for each amount from coin to amount
        for (int i = coin; i <= amount; ++i) {
            dp[i] += dp[i - coin];
        }
    }
    
    return dp[amount];

        
    }
};