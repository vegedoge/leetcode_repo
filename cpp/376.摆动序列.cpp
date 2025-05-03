/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include<vector>

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(std::vector<int>& nums) {
        // 计算所有的局部peak数量
        int result = 1;
        int lastDiff = 0;
        int thisDiff = 0;
        if (nums.size() == 1)
            return 1;

        for (int i = 1; i < nums.size(); i++)
        {
            thisDiff = nums[i] - nums[i - 1];
            if((thisDiff < 0 && lastDiff >= 0) || (thisDiff > 0 && lastDiff <= 0)) {
                result += 1;
                lastDiff = thisDiff;    // 只有反转才更新
            }
        }

        return result;
    }
};
// @lc code=end

