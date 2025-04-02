class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        int maxFreq = 0, res = 0, j = 0;

        for (int i = 0; i < n; i++) {
            freq[s[i] - 'A']++;
            maxFreq = max(maxFreq, freq[s[i] - 'A']);

            while (i - j + 1 - maxFreq > k) {
                freq[s[j] - 'A']--;
                j++;
            }

            res = max(res, i - j + 1);
        }
        
        return res;
        
    }
};