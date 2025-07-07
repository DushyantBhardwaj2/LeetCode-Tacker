class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] will store the column where the ball ends up if it reaches (i, j)
        vector<vector<int>> dp(m + 1, vector<int>(n));
        
        // Base case: if the ball reaches the bottom row (m), it comes out in the same column
        for (int j = 0; j < n; ++j) {
            dp[m][j] = j;
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                int dir = grid[i][j];
                // no need for 1 and -1 seeing 
                int nextCol = j + dir;

                if (nextCol < 0 || nextCol >= n || grid[i][nextCol] != dir) {
                    dp[i][j] = -1;  // Ball gets stuck
                } else {
                    dp[i][j] = dp[i + 1][nextCol];  // Ball moves to next row
                }
            }
        }

        // Prepare result from row 0
        vector<int> ans;
        for (int j = 0; j < n; ++j) {
            ans.push_back(dp[0][j]);
        }

        return ans;
    }
};
