class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int prefixSum = 0, res = 0;

        for (int num : nums) {
            prefixSum += num;
            int mod = ((prefixSum % k) + k) % k;
            res += count[mod];
            count[mod]++;
        }
        return res;

        
    }
};