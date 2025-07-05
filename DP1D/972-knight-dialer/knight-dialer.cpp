class Solution {
public:
    int knightDialer(int n) {
        if (n == 1)
            return 10;
        map<int, long long> m;
        map<int, long long> temp;
        for (int i = 0; i <= 9; i++) {
            m[i]++;
        }
        long long mod = 1e9 + 7;
        while (n - 1 > 0) {
            for (int i = 0; i <= 9; i++) {
                if (i == 0) {
                    temp[i] = (m[4] + m[6]) % mod;
                }
                if (i == 1) {
                    temp[i] = (m[8] + m[6]) % mod;
                }
                if (i == 2) {
                    temp[i] = (m[7] + m[9]) % mod;
                }
                if (i == 3) {
                    temp[i] = (m[4] + m[8]) % mod;
                }
                if (i == 4) {
                    temp[i] = (m[3]+m[0] + m[9]) % mod;
                    
                }
                if (i == 6) {
                    temp[i] = (m[7] + m[1]+m[0]) % mod;
                }
                if (i == 7) {
                    temp[i] = (m[2] + m[6]) % mod;
                }
                if (i == 8) {

                    temp[i] = (m[1] + m[3]) % mod;
                }
                if (i == 9) {

                    temp[i] = (m[4] + m[2]) % mod;
                }
            }
            n--;
            m = temp;
        }
        long long sum = 0;

        for (int i = 0; i <= 9; i++) {
            sum = (sum + m[i]) % mod;
        }
        return sum;
    }
};