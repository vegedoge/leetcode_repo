/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include<vector>
#include<algorithm>
// @lc code=start
class Solution {
public:
    int hIndex(std::vector<int>& citations) {
        std::sort(citations.begin(), citations.end(), std::greater<int>());
        int i;
        for (i = 0; i < citations.size(); ++i)
        {
            if(citations[i] >= i + 1) {
                continue;
            } else {
                return i;
            }
        }
        return i;
    }
};
// @lc code=end

