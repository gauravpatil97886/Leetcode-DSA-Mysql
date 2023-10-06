class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int numThrees = n / 3, remainder = n % 3;
        if (remainder == 0) return pow(3, numThrees);
        if (remainder == 1) return pow(3, numThrees - 1) * 4;
        return pow(3, numThrees) * 2;
    }
};
