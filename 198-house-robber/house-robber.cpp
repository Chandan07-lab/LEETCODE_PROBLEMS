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
