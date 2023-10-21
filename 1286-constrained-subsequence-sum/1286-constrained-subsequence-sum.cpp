class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        maxHeap.push({nums[0], 0});
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            while (i - maxHeap.top().second > k) {
                maxHeap.pop();
            }

            int currentSum = max(0, maxHeap.top().first) + nums[i];
            maxSum = max(maxSum, currentSum);
            maxHeap.push({currentSum, i});
        }

        return maxSum;
    }
};
