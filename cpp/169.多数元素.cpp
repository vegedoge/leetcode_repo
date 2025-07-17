/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target;
        int pos = 0;
        int neg = 0;
        for (auto temp: nums) {
            if (pos - neg == 0) {
                target = temp;
            }
            if (temp == target) {
                pos += 1;
            } else {
                neg += 1;
            }
        }

    return target;
};
// @lc code=end

