/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */
#include <map>
#include <vector>

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        std::map<int, int> values;
        int max_num = 0;
        for (const auto& num: nums) {
            values[num] += num;
            if (num > max_num) {
                max_num = num;
            }
        }

        std::vector<int> value_sum(max_num + 1, 0); // value sum: 对应位置的值求和
        for (const auto& [num, pts]: values) {
            value_sum[num] = pts;
        }

        std::vector<int> dp(max_num + 1, 0);   // dp: 位置结尾的最大点数和
        dp[0] = 0;
        dp[1] = value_sum[1];

        for (int i = 2; i < max_num + 1; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + value_sum[i]);
        }

        return dp[max_num];
    }
};
// @lc code=end

