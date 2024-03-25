#
# @lc app=leetcode.cn id=67 lang=python3
#
# [67] 二进制求和
#

# @lc code=start
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        a = a[::-1]
        b = b[::-1]
        len_a = len(a)
        len_b = len(b)
        gap = len_a - len_b
        while gap > 0:
            b += "0"
            gap -= 1
        while gap < 0:
            a += "0"
            gap += 1
        i, carry= 0, 0
        result= ''
        while i < len(a):
            added = int(a[i]) + int(b[i]) + carry
            carry = 0
            if added == 2:
                result += "0"
                carry = 1
            elif added == 3:
                result += "1"
                carry = 1
            else:
                result += str(added)
            i += 1
        if carry == 1:
            result += "1"
            
        return result[::-1]    
    
app = Solution()    
app.addBinary("1", "111")
                        
                
# @lc code=end

