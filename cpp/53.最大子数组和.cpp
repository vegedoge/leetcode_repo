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
        // vector<int> sum_ups;
        // int sum_up = 0, new_sum_up = 0;
        // int max_sum = nums[0];
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     new_sum_up = sum_up + nums[i];
        //     if (new_sum_up < nums[i]) {
        //         sum_up = nums[i];
        //     } else {
        //         sum_up = new_sum_up;
        //     }
        //     max_sum = std::max(max_sum, sum_up);
        // }
        // return max_sum;

        // dp
        // dp[i]代表到第i个元素的最大和
        vector<int> dp(nums.size(), 0);
        int local_sum = 0;
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > result)
                result = dp[i];
        }

        return result;
    }
};
// @lc code=end

