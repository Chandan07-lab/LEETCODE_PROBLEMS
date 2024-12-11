class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int maxBeauty = 0;
        
        // Create a frequency array to track changes.
        vector<int> freq(300001, 0);

        // Increment and decrement ranges based on the effect of `k`.
        for (int num : nums) {
            int start = max(0, num - k);
            int end = num + k;
            freq[start]++;
            freq[end + 1]--;
        }

        // Calculate the prefix sum to determine the frequency of each value.
        int currentFreq = 0;
        for (int i = 0; i <= 300000; i++) {
            currentFreq += freq[i];
            maxBeauty = max(maxBeauty, currentFreq);
        }

        return maxBeauty;
    }
};