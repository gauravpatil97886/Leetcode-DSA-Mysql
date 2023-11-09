class Solution {
public:
    int countHomogenous(string a) {
        const int MOD = 1000000007;
        long long b = 0;
        int c = 1;

        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i - 1]) {
                c++;
            } else {
                b = (b + (1LL * c * (c + 1) / 2)) % MOD;
                c = 1;
            }
        }

        b = (b + (1LL * c * (c + 1) / 2)) % MOD;

        return static_cast<int>(b);
    }
};
