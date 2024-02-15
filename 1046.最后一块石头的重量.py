#
# @lc app=leetcode.cn id=1046 lang=python3
#
# [1046] 最后一块石头的重量
#

# @lc code=start
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        while len(stones) > 1:
            max_value = max(stones)
            max_index = stones.index(max_value)
            
# @lc code=end

