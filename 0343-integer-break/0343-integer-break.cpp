class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int numThrees = n / 3, remainder = n % 3;
        
        int result;
        if (remainder == 0) {
            result = 1;
            for (int i = 0; i < numThrees; ++i) {
                result *= 3;
            }
        } else if (remainder == 1) {
            result = 4;
            for (int i = 0; i < numThrees - 1; ++i) {
                result *= 3;
            }
        } else {
            result = 2;
            for (int i = 0; i < numThrees; ++i) {
                result *= 3;
            }
        }
        
        return result;
    }
};
