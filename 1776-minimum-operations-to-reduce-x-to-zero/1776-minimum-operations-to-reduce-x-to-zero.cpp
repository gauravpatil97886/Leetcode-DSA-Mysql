class Solution {
public:
    int minOperations(std::vector<int>& nums, int x) {
        int target = 0, n = nums.size();
        for (int num : nums) target += num;
        target -= x;
        
        if (target == 0) return n;
        
        int max_len = 0, curr_sum = 0, left = 0;
        
        for (int right = 0; right < n; ++right) {
            curr_sum += nums[right];
            while (left <= right && curr_sum > target) {
                curr_sum -= nums[left];
                left++;
            }
            if (curr_sum == target) {
                max_len = std::max(max_len, right - left + 1);
            }
        }
        
        return max_len ? n - max_len : -1;
    }
};