/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // assume 背包容量是 sum/2
        // 装满背包如果价值正好也是 sum/2 match
        // 那么就是dp[sum/2] = sum/2
        vector<int> dp(10001, 0);
        int sum = 0;
        int target = 0;

        // get target
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            return false;
        } else {
            target = sum / 2;
        }

        // dp
        for (int j = 0; j < nums.size(); j++) {
            for (int k = target; k >= nums[j]; k--) {
                dp[k] = max(dp[k], dp[k - nums[j]] + nums[j]);
            }
        }

        if (dp[target] == target)
            return true;
        return false;
    }
};
// @lc code=end

