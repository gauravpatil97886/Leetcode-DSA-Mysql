class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        int k = unique(nums.begin(), nums.end()) - nums.begin();
        
        int minOp = INT_MAX;
        
        for (int left = 0, right = 0; right < k; right++) {
            while (left < right && (nums[left] + n - 1) < nums[right]) {
                left++;
            }
            
            minOp = min(minOp, n - (right - left + 1));
        }
        
        return minOp;
    }
};
