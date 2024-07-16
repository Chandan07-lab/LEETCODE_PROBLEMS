class Solution {
public:
    int minDistance(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Fill dp[][] in bottom-up manner
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // If the first string is empty, insert all characters of the second string
                if (i == 0) {
                    dp[i][j] = j; // Min. operations = j
                }
                // If the second string is empty, remove all characters of the first string
                else if (j == 0) {
                    dp[i][j] = i; // Min. operations = i
                }
                // If the last characters are the same, ignore the last char and recur for the remaining string
                else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // If the last character is different, consider all possibilities and find the minimum
                else {
                    dp[i][j] = 1 + min({dp[i][j - 1],    // Insert
                                        dp[i - 1][j],    // Remove
                                        dp[i - 1][j - 1] // Replace
                                       });
                }
            }
        }

        return dp[m][n];
    }
};