class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
    int n = grid[0].size();

    // Create a dp array to store the minimum path sum
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the first row and column
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    // Compute the minimum path sum for each cell
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    // Return the minimum path sum for the last cell
    return dp[m-1][n-1];
    }
};