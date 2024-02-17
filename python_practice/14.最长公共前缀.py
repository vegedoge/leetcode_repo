#
# @lc app=leetcode.cn id=14 lang=python3
#
# [14] 最长公共前缀
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_str = min(strs, key = len)
        min_len = len(min_str)
        
        prefix = []
        for i in range(min_len):
            prefix.append(min_str[i])
            for str in strs:
                if str[i] != min_str[i]:
                    prefix.pop()
                    return "".join(prefix)
            
        return "".join(prefix)
            
# @lc code=end

