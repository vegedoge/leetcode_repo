#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        window = set()
        left = 0
        right = 0
        record = 0
        while right < len(s):
            if s[right] not in window:
                window.add(s[right])
                record = max(right - left + 1, record)
                right += 1
            else:
                window.remove(s[left])
                left += 1 
        
        return record
                            
            
# @lc code=end

