#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#
from typing import List


# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        max_distance = 0
        end_index = len(nums) - 1
        if nums == [0]:
            return True
        for i, this_jump in enumerate(nums):
            if max_distance >= i and i + this_jump >= max_distance:
                max_distance = i + this_jump
                if max_distance >= end_index:
                    return True

        return False

    # def canJump(self, nums: List[int]) -> bool:

    #     def dfs(residue: List[int]) -> bool:
    #         left_len = len(residue)
    #         this_jump = residue[0]
    #         if left_len == 1:
    #             return True
    #         elif this_jump >= left_len:
    #             return True
    #         else:
    #             while this_jump > 0:
    #                 flag = dfs(residue[this_jump:])
    #                 this_jump -= 1
    #                 if flag:
    #                     return True
    #             return False

    #     return dfs(nums)


# test = Solution()
# test.canJump([0])


# @lc code=end
