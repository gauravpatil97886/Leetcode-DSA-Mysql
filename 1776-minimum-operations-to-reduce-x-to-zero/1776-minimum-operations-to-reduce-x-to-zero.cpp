class Solution {
public:
    int minOperations(vector<int>& nums, int targetSum) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum - targetSum;

        if (target < 0) return -1;
        if (target == 0) return nums.size();

        int n = nums.size();
        int minOps = INT_MAX;
        int currSum = 0, left = 0, right = 0;

        while (right < n) {
            currSum += nums[right++];
            while (currSum > target && left < n) currSum -= nums[left++];
            if (currSum == target) minOps = min(minOps, n - (right - left));
        }

        return (minOps == INT_MAX) ? -1 : minOps;
    }
};
