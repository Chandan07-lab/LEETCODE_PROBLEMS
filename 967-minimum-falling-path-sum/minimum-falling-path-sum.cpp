class Solution {
public:
       int minFallingPathSumHelper(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& memo) {
    int n = matrix.size();

    
    if (col < 0 || col >= n) return INT_MAX;

    
    if (row == n - 1) return matrix[row][col];

    
    if (memo[row][col] != INT_MAX) return memo[row][col];

    
    int down = minFallingPathSumHelper(matrix, row + 1, col, memo);
    int downLeft = minFallingPathSumHelper(matrix, row + 1, col - 1, memo);
    int downRight = minFallingPathSumHelper(matrix, row + 1, col + 1, memo);

    memo[row][col] = matrix[row][col] + min({down, downLeft, downRight});
    return memo[row][col];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int minPathSum = INT_MAX;
    vector<vector<int>> memo(n, vector<int>(n, INT_MAX));

    for (int col = 0; col < n; ++col) {
        minPathSum = min(minPathSum, minFallingPathSumHelper(matrix, 0, col, memo));
    }

    return minPathSum;
}

    
 };
// int minFallingPathSum(vector<vector<int>>& matrix) {
//     int n = matrix.size();

//     // Start from the second last row and move upwards
//     for (int row = n - 2; row >= 0; --row) {
//         for (int col = 0; col < n; ++col) {
//             int down = matrix[row + 1][col];
//             int downLeft = (col > 0) ? matrix[row + 1][col - 1] : INT_MAX;
//             int downRight = (col < n - 1) ? matrix[row + 1][col + 1] : INT_MAX;

//             matrix[row][col] += min({down, downLeft, downRight});
//         }
//     }

//     // The answer is the minimum value in the first row
//     return *min_element(matrix[0].begin(), matrix[0].end());
 // }