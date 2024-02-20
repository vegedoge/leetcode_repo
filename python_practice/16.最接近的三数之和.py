#
# @lc app=leetcode.cn id=16 lang=python3
#
# [16] 最接近的三数之和
#
# from typing import List
# @lc code=start
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        nums.sort()
        i = 0
        gap = abs(nums[0] + nums[1] + nums[2] - target)
        result = nums[0] + nums[1] + nums[2]
        while i < n - 2:
            j = i + 1
            k = n - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                gap_temp = sum - target
                if gap_temp > 0:
                    k -= 1
                elif gap_temp < 0:
                    j += 1
                elif gap_temp == 0:
                    return target
                if abs(gap_temp) < gap:
                    gap = abs(gap_temp)
                    result = sum
            i += 1
        return result
            
# s = Solution()
# s.threeSumClosest([-1, 2, 1, -4], 1)
# @lc code=end

