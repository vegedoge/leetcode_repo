/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
using namespace std;
#include <vector>
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        for (int price: prices) {
            if (price > buy) {
                profit += price - buy;
            }
            buy = price;
        }
        return profit;
    }
};
// @lc code=end

