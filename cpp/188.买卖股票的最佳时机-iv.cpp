/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include<vector>
#include<algorithm>
// @lc code=start
class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || k == 0) {
            return 0;
        }

        // 记录上一次交易 而不是每个交易日
        // dp[j][x]表示第j次交易后持有股票与否的最大利润
        std::vector<std::vector<int>> dp(k + 1, std::vector<int>(2));

        for (int j = 0; j <= k; ++j) {
            // 持有的情况
            dp[j][1] = -prices[0];
            // 不持有
            dp[j][0] = 0;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // 不持有
                dp[j][0] = std::max(dp[j][0], dp[j][1] + prices[i]);
                // 持有
                dp[j][1] = std::max(dp[j][1], dp[j-1][0] - prices[i]);
            }
        }

        return dp[k][0];
    }
};
// @lc code=end

