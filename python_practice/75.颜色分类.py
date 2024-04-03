#
# @lc app=leetcode.cn id=75 lang=python3
#
# [75] 颜色分类
#
from typing import List


# @lc code=start
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        def swap(nums, index1, index2):
            '''swap two element position'''
            nums[index1], nums[index2] = nums[index2], nums[index1]

        length = len(nums)
        # pointer for 0 part and 2 part
        zero_index = 0
        two_index = length - 1
        i = 0

        while i <= two_index:
            if nums[i] == 0:
                swap(nums, i, zero_index)
                zero_index += 1
                i += 1
            elif nums[i] == 1:
                i += 1
            else:
                swap(nums, i, two_index)
                two_index -= 1


app = Solution()
test = app.sortColors([2, 0, 1])


# @lc code=end
