/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
using namespace std;
#include <vector>
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sum_ups;
        int sum_up = 0, new_sum_up = 0;
        int max_sum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            new_sum_up = sum_up + nums[i];
            if (new_sum_up < nums[i]) {
                sum_up = nums[i];
            } else {
                sum_up = new_sum_up;
            }
            max_sum = std::max(max_sum, sum_up);
        }
        return max_sum;
    }
};
// @lc code=end

