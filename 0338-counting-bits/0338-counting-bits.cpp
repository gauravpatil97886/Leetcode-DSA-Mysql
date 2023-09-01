class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0); // Initialize the result array
        
        for (int i = 1; i <= n; ++i) {
            // Use the property: ans[i] = ans[i >> 1] + (i & 1)
            ans[i] = ans[i >> 1] + (i & 1);
        }
        
        return ans;
    }
};
