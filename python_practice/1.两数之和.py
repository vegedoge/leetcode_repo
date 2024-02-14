#
# @lc app=leetcode.cn id=1 lang=python3
#
# [1] 两数之和
#
from typing import List

# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # use dict as our value container
        num_dic = dict()
        for index, num in enumerate(nums):
            # see if in hash keys
            if target - num in num_dic:
                return [index, num_dic[target - num]]
            num_dic[num] = index
        return []
                
        
        
# @lc code=end

