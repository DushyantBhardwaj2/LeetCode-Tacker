class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diffbit;
        for (int i = 0; i < 32; i++) {
            int bitSum = 0;
            for (int num : nums) {
                if (num & (1 << i)) {
                    bitSum++;
                }
            }
            if (bitSum % 2 != 0) {
                diffbit = i;
            }
        }
        int one = 0;
        for (int num : nums) {
            if (num & (1 << diffbit)) {
                one^=num;
            }
        }
        int two=0;
        for (int num : nums) {
            two^=num;
        }
        two^=one;
        return {one,two};

    }
};