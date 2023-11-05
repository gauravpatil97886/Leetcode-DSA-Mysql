class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;

        while (s.back() == ' ' && !s.empty()) {
            s.pop_back();
        }

        reverse(s.begin(), s.end());

        for (char c : s) {
            if (c == ' ') {
                break;
            }
            length++;
        }

        return length;
    }
};
