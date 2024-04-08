#
# @lc app=leetcode.cn id=264 lang=python3
#
# [264] 丑数 II
#


# @lc code=start
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly_array = [1] * n
        idx_2, idx_3, idx_5 = 0, 0, 0
        for i in range(1, n):
            mul_2, mul_3, mul_5 = (
                ugly_array[idx_2] * 2,
                ugly_array[idx_3] * 3,
                ugly_array[idx_5] * 5,
            )
            ugly_array[i] = min(mul_2, mul_3, mul_5)
            if ugly_array[i] == mul_2:
                idx_2 += 1
            if ugly_array[i] == mul_3:
                idx_3 += 1
            if ugly_array[i] == mul_5:
                idx_5 += 1
        return ugly_array[-1]


# @lc code=end
