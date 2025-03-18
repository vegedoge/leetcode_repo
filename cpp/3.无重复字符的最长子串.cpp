/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_set<int> local;
        for (right = 0; right < s.size(); right++) {
            while(local.find(s[right]) != local.end()) {
                local.erase(s[left++]);
            }
            max_len = max(max_len, right - left + 1);
            local.insert(s[right]);
        }
        return max_len;
    }
};
// @lc code=end

