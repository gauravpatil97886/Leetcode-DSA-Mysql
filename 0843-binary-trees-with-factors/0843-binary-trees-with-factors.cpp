class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int MOD = 1000000007;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        unordered_map<int, long long> dp;
        
        for (int i = 0; i < n; i++) {
            dp[arr[i]] = 1;
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int complement = arr[i] / arr[j];
                    if (dp.count(complement)) {
                        dp[arr[i]] = (dp[arr[i]] + (dp[arr[j]] * dp[complement]) % MOD) % MOD;
                    }
                }
            }
        }
        
        long long total = 0;
        for (int i = 0; i < n; i++) {
            total = (total + dp[arr[i]]) % MOD;
        }
        
        return total;
    }
};
