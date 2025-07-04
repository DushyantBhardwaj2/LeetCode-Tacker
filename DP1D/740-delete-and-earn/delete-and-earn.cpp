class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> points(maxNum + 1, 0);
        // i am creating a array from 0 to max element 
        // so that we can use this question as house robber wala 
        // you can not traverse adjacent 
        
        // Sum values for each unique number
        for (int num : nums) {
            points[num] += num;
        }

        vector<int> dp(maxNum + 1, 0);
        dp[0] = points[0];
        dp[1] = max(points[0], points[1]);

        for (int i = 2; i <= maxNum; ++i) {
            dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
        }

        return dp[maxNum];
    }
};
