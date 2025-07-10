class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int f(int ind, int day, vector<int>& jobDifficulty) {
        if (day == 0 && ind == n) return 0; // all jobs assigned
        if (day == 0 || n - ind < day) return 1e9; // not enough jobs to assign

        if (dp[ind][day] != -1) return dp[ind][day];

        int maxDiff = 0;
        int ans = INT_MAX;

        for (int i = ind; i <= n - day; ++i) {
            maxDiff = max(maxDiff, jobDifficulty[i]);
            ans = min(ans, maxDiff + f(i + 1, day - 1, jobDifficulty));
        }

        return dp[ind][day] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if (n < d) return -1; // not enough jobs

        dp = vector<vector<int>>(n, vector<int>(d + 1, -1));
        return f(0, d, jobDifficulty);
    }
};
