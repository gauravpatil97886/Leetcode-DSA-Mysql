class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }

    vector<int> findArray(vector<int>& pref) {
        if (pref.empty()) return vector<int>();

        for (int i = pref.size() - 1; i > 0; i--)
            pref[i] ^= pref[i - 1];

        return pref;
    }
};
