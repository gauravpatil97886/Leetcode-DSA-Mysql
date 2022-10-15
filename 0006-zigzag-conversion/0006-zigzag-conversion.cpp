class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) {
            return s;
        }
        
        string ss;
        ss.reserve(s.size());
        
        for (int i = 0; i < nRows; i++) {
            for(int j = 0, k = i; k < s.size(); j++) {
                ss.push_back(s[k]);
                if (i == 0 || i == (nRows-1)) {
                    k += 2 * (nRows - 1);    
                } else {
                    if (j % 2 == 0) {
                        k += 2 * (nRows - i - 1);
                    } else {
                        k += 2 * i;
                    }
                }
            }
        }
        
        return ss;
    }
};