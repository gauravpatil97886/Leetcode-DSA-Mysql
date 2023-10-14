class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        const int n = cost.size();
        vector<int> dp(n + 1, 5e8);
        dp[0] = 0;

        for (int i = 0; i < n; ++i) {
            for (int w = n; w > 0; --w) {
                dp[w] = min(dp[w], dp[max(w - time[i] - 1, 0)] + cost[i]);
            }
        }

        return dp[n];
    }
};
