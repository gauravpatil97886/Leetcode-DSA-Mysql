class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> count(128, 0);

        for (char ch : s) {
            count[ch]++;
        }

        for (char ch : t) {
            count[ch]--;
        }

        for (int i = 0; i < 128; i++) {
            if (count[i] < 0) {
                return i;
            }
        }

        return ' ';
    }
};
