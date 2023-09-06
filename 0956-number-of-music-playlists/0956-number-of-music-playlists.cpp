class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1));
        dp[0][0] = 1;
        
        for (int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[j][i] = (dp[j - 1][i - 1] * j) % MOD;
                if (j > k) {
                    dp[j][i] = (dp[j][i] + (dp[j][i - 1] * (j - k)) % MOD) % MOD;
                }
            }
        }
        
        return dp[n][goal];
    }
};
