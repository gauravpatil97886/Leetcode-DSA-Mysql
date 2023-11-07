class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> a_b;
        int a = dist.size();
        for (int b = 0; b < a; ++b) {
            a_b.push_back((dist[b] + speed[b] - 1) / speed[b]);
        }
        sort(a_b.begin(), a_b.end());
        for (int a_t = 0; a_t < a; ++a_t) {
            if (a_t >= a_b[a_t]) {
                return a_t;
            }
        }
        return a;
    }
};
