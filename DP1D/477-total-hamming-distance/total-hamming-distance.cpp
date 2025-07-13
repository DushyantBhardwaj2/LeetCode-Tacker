class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        bool allZero = false;
        int ans=0;
        while (!allZero) {
            allZero=true;
            int zero = 0;
            int one = 0;
            for (int i = 0; i < nums.size(); i++) {
                if(nums[i]!=0) allZero = false;
                if((nums[i]&1)==1) one++;
                else zero++;
                nums[i]>>=1;

            }
            ans+=zero*one;
        }
        return ans;
    }
};