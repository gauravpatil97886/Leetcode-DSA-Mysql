class Solution {
public:
    const int MOD = 1000000007;

    int nthMagicalNumber(int N, int A, int B) {
        if (A > B) swap(A, B);
        uint64_t leastCommonMultiple = lcm(A, B);
        uint64_t low = 0;
        uint64_t high = (uint64_t)N * A;
        while (low < high) {
            uint64_t middle = low + (high - low) / 2;
            uint64_t count = middle / A + middle / B - middle / leastCommonMultiple;
            if (count < N) low = middle + 1;
            else high = middle;
        }
        return low % MOD;
    }
};
