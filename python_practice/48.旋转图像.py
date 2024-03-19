#
# @lc app=leetcode.cn id=48 lang=python3
#
# [48] 旋转图像
#
from typing import List
import math

# @lc code=start
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        n = len(matrix)
        round = math.ceil(n // 2)
        # rounds of rotation
        for i in range(round):
            # movement of elements in one round
            for j in range(i, n-1-i):
                temp = matrix[i][j]
                # left up <- left down 
                matrix[i][j] = matrix[n-1-j][i]
                # left down <- right down
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
                # right down <- right up
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
                # right up <- left up
                matrix[j][n-1-i] = temp
 
# @lc code=end

