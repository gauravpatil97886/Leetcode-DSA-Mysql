class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurrence = binarySearch(nums, target, true);
        int lastOccurrence = binarySearch(nums, target, false);
        return {firstOccurrence, lastOccurrence};
    }
    
    int binarySearch(vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                result = mid;
                if (findFirst) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }
};
