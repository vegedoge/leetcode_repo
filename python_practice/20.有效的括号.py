#
# @lc app=leetcode.cn id=20 lang=python3
#
# [20] 有效的括号
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pair = {"(": ")", "[": "]", "{": "}"}
        for string in s:
            if string in ["(", "{", "["]:
                stack.append(string)
            # check if empty stack
            elif not stack or pair[stack.pop()] != string:
                return False
        return len(stack) == 0 
                
# @lc code=end

