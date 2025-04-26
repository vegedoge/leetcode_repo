/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include<vector>

// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        //dp[i] 到i个之前的最长连续递增子序列长度
        std::vector<int> dp(nums.size(), 1);
        dp[0] = 1; // for init
        int maxLen = 1;

        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                dp[i] = std::max(dp[i], dp[i - 1] + 1);
                maxLen = std::max(maxLen, dp[i]);
            }
        }

        return maxLen;
    }
};
// @lc code=end

