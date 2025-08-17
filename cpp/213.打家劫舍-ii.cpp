/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp_1(n + 1, 0);
        vector<int> dp_2(n + 1, 0);

        dp_1[1] = nums[0];
        for (int i = 2; i < n; ++i)
        {
            dp_1[i] = std::max(dp_1[i - 1], nums[i - 1] + dp_1[i - 2]);
        }

        dp_2[1] = 0;
        for (int i = 2; i < n + 1; ++i)
        {
            dp_2[i] = std::max(dp_2[i - 1], nums[i - 1] + dp_2[i - 2]);
        }

        if (dp_2[n] > dp_1[n-1]) {
            return dp_2[n];
        } else {
            return dp_1[n - 1];
        }
    }
};
// @lc code=end

