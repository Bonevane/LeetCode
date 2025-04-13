class Solution {
    public:
        int mod = 1000000007;
    
        int countGoodNumbers(long long n) {
            return (int)(quickmul(5, (n + 1) / 2) * quickmul(4, n / 2) % mod);
        }
    
        long long quickmul(int x, long long y) {
            long long ret = 1;
            long long mul = x;
            while (y > 0) {
                if (y % 2 == 1) {
                    ret = (ret * mul) % mod;
                }
                mul = (mul * mul) % mod;
                y /= 2;
            }
            return ret;
        }
    };