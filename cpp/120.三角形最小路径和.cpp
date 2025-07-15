/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include<vector>

// @lc code=start
class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        int m = triangle.size() + 1;
        std::vector<std::vector<int>> dp(m, std::vector<int>(m, 10001));
        dp[0][0] = 0;

        for (int i = 1; i < m; ++i) {
            
            for (int j = 1; j <= i; ++j) {
                dp[i][j] = triangle[i - 1][j - 1] + std::min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
        }

        std::vector<int> last_line = dp[m-1];
        int min_sum = __INT32_MAX__;
        for (int val: last_line){
            min_sum = val < min_sum ? val : min_sum;
        }

        return min_sum;
    }
};
// @lc code=end

