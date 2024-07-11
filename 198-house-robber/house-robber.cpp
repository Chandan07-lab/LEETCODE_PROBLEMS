// class Solution {
// public:
//     int func(int i, vector<int>& nums) {
//         if (i >= nums.size()) {
//             return 0;
//         }
        
//         int robCurrent = nums[i] + func(i + 2, nums);
//         int skipCurrent = func(i + 1, nums);
//         return max(robCurrent, skipCurrent);
//     }

//     int rob(vector<int>& nums) {
//       .
//         if (nums.empty()) {
//             return 0;
//         }

//         return func(0, nums);
//     }
// };
class Solution {
public:
    int rob(vector<int>& nums) {
        // Handle empty array case
        if (nums.empty()) {
            return 0;
        }

        // Initialize variables for dynamic programming
        int prevMax = 0; // Maximum amount possible for robbing the previous house
        int currMax = nums[0]; // Maximum amount possible including the current house

        // Iterate through the nums vector starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            // Calculate the maximum amount considering robbing the current house
            int tempMax = prevMax + nums[i];

            // Update the previous and current maximums
            prevMax = currMax;
            currMax = max(currMax, tempMax);
        }

        // Return the final maximum amount
        return currMax;
    }
};
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==0)
//             return 0;
//         else if(n==1) 
//             return nums[0];

//         vector<int> dp(n, 0);

//         dp[0] = nums[0];
//         dp[1] = max(nums[1], dp[0]);

//         for(int i=2; i<n ; i++) {
//             dp[i] = max(dp[i-1], nums[i]+dp[i-2]);
//         }
//         return dp[n-1];
        
//     }
// }
