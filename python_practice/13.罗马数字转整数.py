#
# @lc app=leetcode.cn id=13 lang=python3
#
# [13] 罗马数字转整数
#

# @lc code=start
class Solution:
    def romanToInt(self, s: str) -> int:
        int_s, i = 0, 0
        while i < len(s):
            if i < len(s)-1:  
                if s[i] == "M":
                    int_s += 1000
                elif s[i] == "D":
                    int_s += 500
                elif s[i] == "L":
                    int_s += 50
                elif s[i] == "V":
                    int_s += 5
                elif s[i] == "C":
                    if s[i+1] == "D":
                        int_s += 400
                        i += 1
                    elif s[i+1] == "M":
                        int_s += 900
                        i += 1
                    else:
                        int_s += 100
                elif s[i] == "X":
                    if s[i+1] == "L":
                        int_s += 40
                        i += 1
                    elif s[i+1] == "C":
                        int_s += 90
                        i += 1
                    else:
                        int_s += 10
                elif s[i] == "I":
                    if s[i+1] == "V":
                        int_s += 4
                        i += 1
                    elif s[i+1] == "X":
                        int_s += 9
                        i += 1
                    else:
                        int_s += 1
            else:
                if s[i] == "M":
                    int_s += 1000
                elif s[i] == "D":
                    int_s += 500
                elif s[i] == "L":
                    int_s += 50
                elif s[i] == "V":
                    int_s += 5
                elif s[i] == "C":
                    int_s += 100
                elif s[i] == "X":
                    int_s += 10
                elif s[i] == "I":
                    int_s += 1    
            i += 1  
        return int_s

solution = Solution()
ans = solution.romanToInt("MCMXCIV")             
                
# @lc code=end

