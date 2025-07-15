/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include<algorithm>
#include<vector>
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }

        std::vector<std::vector<std::vector<int>>> dp(prices.size(),
                                                      std::vector<std::vector<int>>(3, std::vector<int>(2)));

        // k: 当前允许的最大交易次数
        for (int k = 0; k <= 2; ++k) {
            // 第一天不持股
            dp[0][k][0] = 0;
            // 第一天就持股
            dp[0][k][1] = -prices[0];
        }

        for (int i = 1; i < prices.size(); ++i) {
            for (int k = 1; k <= 2; ++k) {
                // 不持股
                dp[i][k][0] = std::max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                // 持股, 买入要减少一次k
                dp[i][k][1] = std::max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
            }
        }

        return dp[prices.size() - 1][2][0];
    }
};
// @lc code=end

