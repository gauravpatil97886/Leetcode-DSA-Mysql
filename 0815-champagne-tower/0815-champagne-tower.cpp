class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> current(101, 0.0);
        current[0] = poured;
        
        for (int i = 0; i < query_row; ++i) {
            vector<double> next(101, 0.0);
            for (int j = 0; j <= i; ++j) {
                double overflow = max(0.0, (current[j] - 1.0) / 2.0);
                next[j] += overflow;
                next[j + 1] += overflow;
            }
            swap(current, next);
        }
        
        return min(1.0, current[query_glass]);
    }
};
