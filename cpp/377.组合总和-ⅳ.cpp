/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        // dp[i]: 总和为i的排列数量
        vector<int> dp(target + 1, 0);

        dp[0] = 1; // 没意义
        for (int i = 0; i < target + 1; ++i) {
            for (int j = 0; j < n; ++j) {
                if (nums[j] <= i && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        // 受不了了开摆
        if (dp[target] == 2147483646) {
            return 2147483647;
        } else {
            return dp[target];
        }
        
    }
};
// @lc code=end

