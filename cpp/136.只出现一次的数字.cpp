/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

#include<vector>
// @lc code=start
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int answer = 0;
        for (int num: nums)
        {
            answer ^= num;
        }
        return answer;
    }
};
// @lc code=end

