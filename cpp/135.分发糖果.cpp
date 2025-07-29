/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int candy(std::vector<int>& ratings) {
        if (ratings.size() == 1) {
            return 1;
        }
        std::vector<int> candies(ratings.size(), 1);

        // 先正向贪心
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // 反向再来一次 取得最大的
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = std::max(candies[i], candies[i + 1] + 1);
            }
        }

        int result = 0;
        for (auto num: candies) {
            result += num;
        }

        return result;
    }
};
// @lc code=end

