class Solution {
public:
    int MOD = 1e9 + 7;

    // ✅ Change 1: Function now returns a pair of {minProduct, maxProduct}
    pair<long long, long long> f(int row, int col, int& m, int& n,
                                 vector<vector<int>>& grid,
                                 vector<vector<pair<long long, long long>>>& dp) {
        // Base case: at destination cell
        if (row == m - 1 && col == n - 1) {
            return {grid[row][col], grid[row][col]};
        }

        // ✅ Change 2: Memoization check using pair
        if (dp[row][col].first != LLONG_MIN) {
            return dp[row][col];
        }

        long long curr = grid[row][col];

        // Initialize values with invalid states
        long long minVal = LLONG_MAX;
        long long maxVal = LLONG_MIN;

        // Move Right
        if (col + 1 < n) {
            auto [minR, maxR] = f(row, col + 1, m, n, grid, dp);
            long long a = curr * minR;
            long long b = curr * maxR;
            minVal = min(minVal, min(a, b));
            maxVal = max(maxVal, max(a, b));
        }

        // Move Down
        if (row + 1 < m) {
            auto [minD, maxD] = f(row + 1, col, m, n, grid, dp);
            long long a = curr * minD;
            long long b = curr * maxD;
            minVal = min(minVal, min(a, b));
            maxVal = max(maxVal, max(a, b));
        }

        // ✅ Change 3: Store the result in dp as a pair of {minProduct, maxProduct}
        return dp[row][col] = {minVal, maxVal};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // ✅ Change 4: DP stores both min and max products as pairs
        vector<vector<pair<long long, long long>>> dp(m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MIN}));

        long long res = f(0, 0, m, n, grid, dp).second;

        // ✅ Change 5: Return -1 if result is negative, else mod it
        return (res < 0) ? -1 : res % MOD;
    }
};
