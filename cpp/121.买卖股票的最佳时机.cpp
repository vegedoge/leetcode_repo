/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int end = prices.size();
        int lowest_price = prices[0];
        int profit = 0;
        int best_deal = 0;
        for (int i = 0; i < end; ++i)
        {
            profit = prices[i] - lowest_price;
            if (profit > best_deal) {
                best_deal = profit;
            }
            if (prices[i] < lowest_price)
            {
                lowest_price = prices[i];
            }
        }
        return best_deal;
    }
};
// @lc code=end

