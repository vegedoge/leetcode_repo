/*
 * @lc app=leetcode.cn id=2401 lang=cpp
 *
 * [2401] 最长优雅子数组
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int longestNiceSubarray(std::vector<int>& nums) {
        // 其实就是和一个大的合集& &不出1就能玩
        int integrate = 0;
        int left, right = 0;
        int sub_len;
        int result = 0;
        for (; right < nums.size(); ++right)
        {
            while ((nums[right] & integrate) != 0) {
                // 其实减也一样
                integrate ^= nums[left];
                left++;
            }

            // +也一样
            integrate |= nums[right];
            sub_len = right - left + 1;
            result = result > sub_len ? result : sub_len;
        }

        return result;
    }
};
// @lc code=end

