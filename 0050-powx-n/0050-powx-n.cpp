class Solution {
public:
    double myPow(double x, long n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            return myPow(1 / x, -n);
        }
        return (n & 1) ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};
