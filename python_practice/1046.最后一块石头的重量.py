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
            del stones[max_index]
            second_value = max(stones)
            sec_index = stones.index(second_value)
            del stones[sec_index]
            remain = max_value - second_value
            if remain:
                stones.append(remain)
        if len(stones) == 0:
            return 0
        else:
            return stones[0]
                
            
# @lc code=end

