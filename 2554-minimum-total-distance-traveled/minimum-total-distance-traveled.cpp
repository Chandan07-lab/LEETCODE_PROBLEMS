class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end()); 
        sort(factory.begin(), factory.end()); 

        int r = robot.size(), f = factory.size();
        
        
        vector<vector<long long>> dp(r + 1, vector<long long>(f + 1, LLONG_MAX / 2));
        
        dp[0][0] = 0; 

        for (int j = 1; j <= f; ++j) { 
            dp[0][j] = 0; 
            for (int i = 1; i <= r; ++i) { 
                long long totalDist = 0;
                for (int k = 0; k <= min(i, factory[j - 1][1]); ++k) { // Consider k robots for factory j
                    if (k > 0) {
                        totalDist += abs(robot[i - k] - factory[j - 1][0]); // Distance for each of k robots
                    }
                    if (dp[i - k][j - 1] < LLONG_MAX / 2) { // Only add if it's a valid (non-overflowing) value
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + totalDist); // Minimize total distance
                    }
                }
            }
        }
        
        return dp[r][f]; // Minimum distance for all robots and factories
    }
};
