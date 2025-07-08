class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));

        // We need to reach (m-1, n-1), so we set a "dummy" destination at (m, n-1) and (m-1, n)
        dp[m][n - 1] = dp[m - 1][n] = 1;

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int minHealthFromNextStep = min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(1, minHealthFromNextStep - dungeon[i][j]);
            }
        }

        return dp[0][0];
    }
};
