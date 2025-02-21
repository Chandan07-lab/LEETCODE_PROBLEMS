class Solution {
public:
int dp[13][10001];
int solve(vector<int>&coins,int i,int t){
    if(i==0){
        if(t%coins[i]==0){
            return t/coins[i];
        }else{
            return 1e9+7;
        }
    }
    if(dp[i][t]!=-1){
        return dp[i][t];
    }

    int nottake=solve(coins,i-1,t);
    int take=INT_MAX;
    if(coins[i]<=t){
        take=1+solve(coins,i,t-coins[i]);
    }

    return dp[i][t]=min(take,nottake);
}



    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        memset(dp,-1,sizeof(dp));
        int ans=solve(coins,n-1,amount);
        if(ans>=1e9+7){
            return -1;
        }else{
            return ans;
        }
    }
};