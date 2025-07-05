class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int, int> dp;
        int maxLen = 0;
        for (int num : arr) {
            dp[num] = 1 + dp[num - difference];
            maxLen = max(maxLen, dp[num]);
        }
        return maxLen;
    
    }
};