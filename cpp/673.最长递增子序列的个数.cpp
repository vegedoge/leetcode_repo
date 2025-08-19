/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp: numsi结尾的最长递增子序列长度
        vector<int> dp(n, 1);
        // count: numsi结尾的最长递增子序列数量
        vector<int> count(n, 1);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j]; // 继承了
                    }
                    else if (dp[j] + 1 == dp[i])
                    {
                        count[i] += count[j];
                    }
                }
            }
        }

        int max_len = 0;
        for (auto len: dp) {
            max_len = len > max_len ? len : max_len;
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] == max_len) {
                result += count[i];
            }
        }

        return result;
    }
};
// @lc code=end

