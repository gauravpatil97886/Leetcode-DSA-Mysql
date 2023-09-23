class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        
        int maxLen = 1;
        unordered_map<string, int> dp;
        
        for (const string& word : words) {
            int len = 1;
            for (int i = 0; i < word.size(); ++i) {
                string pred = word.substr(0, i) + word.substr(i + 1);
                if (dp.find(pred) != dp.end()) {
                    len = max(len, dp[pred] + 1);
                }
            }
            dp[word] = len;
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};
