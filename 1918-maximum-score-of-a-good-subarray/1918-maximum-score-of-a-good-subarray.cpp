class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int n = nums.size();
        int maxScore = nums[k];
        int minVal = nums[k];
        int left = k;
        int right = k;

        while (left > 0 || right < n - 1) {
            if (left == 0)
                ++right;
            else if (right == n - 1)
                --left;
            else if (nums[left - 1] < nums[right + 1])
                ++right;
            else
                --left;
            minVal = min({minVal, nums[left], nums[right]});
            maxScore = max(maxScore, minVal * (right - left + 1));
        }

        return maxScore;
    }
};
