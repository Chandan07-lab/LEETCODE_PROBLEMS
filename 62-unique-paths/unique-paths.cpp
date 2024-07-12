class Solution {
public:

//         int uniquePathsHelper(int m, int n, int i, int j) {
//     // Base case: if the current position is the bottom-right corner, return 1
//     if (i == m - 1 && j == n - 1) {
//         return 1;
//     }
//     // Base case: if the current position is out of the grid, return 0
//     if (i >= m || j >= n) {
//         return 0;
//     }
    
//     // Move right or move down
//     return uniquePathsHelper(m, n, i + 1, j) + uniquePathsHelper(m, n, i, j + 1);
// }

// int uniquePaths(int m, int n) {
//     return uniquePathsHelper(m, n, 0, 0);
// }
        
    


int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    
    // Start from (1,1) as the edges (first row and first column) are all 1
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    
    return dp[m-1][n-1];
}

};
// // Recursive function with memoization to calculate the number of unique paths
// int uniquePathsHelper(int m, int n, int i, int j, vector<vector<int>>& memo) {
//     // Base case: if the current position is the bottom-right corner, return 1
//     if (i == m - 1 && j == n - 1) {
//         return 1;
//     }
//     // Base case: if the current position is out of the grid, return 0
//     if (i >= m || j >= n) {
//         return 0;
//     }
//     // If the result is already computed, return it
//     if (memo[i][j] != -1) {
//         return memo[i][j];
//     }

//     // Move right or move down
//     memo[i][j] = uniquePathsHelper(m, n, i + 1, j, memo) + uniquePathsHelper(m, n, i, j + 1, memo);
//     return memo[i][j];
// }

// int uniquePaths(int m, int n) {
//     vector<vector<int>> memo(m, vector<int>(n, -1));
//     return uniquePathsHelper(m, n, 0, 0, memo);
// }




