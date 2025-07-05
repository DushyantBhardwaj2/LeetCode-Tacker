class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int count = 0;
        int ans = -1;
        int prev = -1;
        for (int x : arr) {
            if (x != prev) {
                if (prev == count) {
                    ans = max(ans, prev);
                }
                prev = x;
                count = 1;
            } else if (x == prev) {
                count++;
            }
        }
        if (prev == count) {
            ans = max(ans, prev);
        }
        return ans;
    }
};