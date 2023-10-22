from typing import List

class Solution:
    def maximumScore(self, nums: List[int], k: int) -> int:
        N = len(nums)
        lo = k
        hi = k
        ans = nums[k]
        mn = nums[k]

        while lo >= 0 and hi < N:
            ans = max(ans, mn * (hi - lo + 1))
            loMn = min(mn, nums[lo - 1] if lo - 1 >= 0 else 0)
            hiMn = min(mn, nums[hi + 1] if hi + 1 < N else 0)

            if loMn >= hiMn:
                mn = loMn
                lo -= 1
            else:
                mn = hiMn
                hi += 1

        return ans
