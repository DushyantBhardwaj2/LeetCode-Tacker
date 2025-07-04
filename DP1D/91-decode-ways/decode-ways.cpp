class Solution {
public:
    int helper(int i, string &s,vector<int>& dp) {
        if (i == s.size()) return 1;          // Reached end: valid path
        if (s[i] == '0') return 0;            // Invalid path: cannot start with '0'
        if(dp[i]!=-1) return dp[i];
        int ways = helper(i + 1, s,dp);          // One digit

        // Check two-digit decode
        if (i + 1 < s.size()) {
            int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (twoDigit >= 10 && twoDigit <= 26) {
                ways += helper(i + 2, s,dp);     // Two digits
            }
        }

        return dp[i]=ways;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return helper(0, s,dp);
    }
};
