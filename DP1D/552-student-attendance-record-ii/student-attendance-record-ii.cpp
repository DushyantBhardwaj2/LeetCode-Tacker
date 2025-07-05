class Solution {
public:
    int mod = 1e9 + 7;
    int dp[100001][3][2]; // dp[day][consecutiveL][absent]

    int f(int day, int n, int l, int a) {
        if (day == n) return 1;
        if (dp[day][l][a] != -1) return dp[day][l][a];

        long long res = 0;
        
        // Present
        res += f(day + 1, n, 0, a);
        
        // Late
        if (l < 2) {
            res += f(day + 1, n, l + 1, a);
        }

        // Absent
        if (a < 1) {
            res += f(day + 1, n, 0, a + 1);
        }

        return dp[day][l][a] = res % mod;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return f(0, n, 0, 0);
    }
};
