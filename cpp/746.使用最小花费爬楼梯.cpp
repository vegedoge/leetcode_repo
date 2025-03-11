/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::vector<int> cost_dp(cost.size() + 1);
        cost_dp[0] = 0;
        cost_dp[1] = 0;
        for (int i = 2; i <= cost.size(); i++) {
            cost_dp[i] = min((cost_dp[i - 1] + cost[i - 1]), (cost_dp[i - 2] + cost[i - 2]));
        }
        return cost_dp.back();
    }
};
// @lc code=end

