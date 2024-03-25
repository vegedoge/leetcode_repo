#
# @lc app=leetcode.cn id=73 lang=python3
#
# [73] 矩阵置零
#

# @lc code=start
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])
        row_zero = set()
        col_zero = set()

        for i in range(rows):
            for j in range(cols):
                if matrix[i][j] == 0:
                    row_zero.add(i)
                    col_zero.add(j)
        
        for i in range(rows):
            for j in range(cols):
                if i in row_zero or j in col_zero:
                    matrix[i][j] = 0
                
            
            
                
        
        
# @lc code=end

