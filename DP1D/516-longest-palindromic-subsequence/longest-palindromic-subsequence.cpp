class Solution {
public:
    int longestPalindromeSubseq(string s) {

        int n = s.length();
        string rs = s;
        reverse(rs.begin(), rs.end());

        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));

        for (int i = 0; i < n; i++) {
            memo[0][i] = 0;
            memo[i][0] = 0;
        }

        for (int ind1 = 1; ind1 <= n; ind1++) {
            for (int ind2 = 1; ind2 <= n; ind2++) {
                if (s[ind1 - 1] == rs[ind2 - 1])
                    memo[ind1][ind2] = 1 + memo[ind1 - 1][ind2 - 1];
                else
                    memo[ind1][ind2] = max(memo[ind1 - 1][ind2], memo[ind1][ind2 - 1]);
            }
        }
        return memo[n][n];
    }
};