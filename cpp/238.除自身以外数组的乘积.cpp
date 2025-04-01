/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int pre_mul = 1;
        int post_mul = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            pre_mul = pre_mul * nums[i-1];
            result[i] = pre_mul;
        }

        for (int j = nums.size()-1; j > 0; j--) {
            post_mul = post_mul * nums[j];
            result[j-1] = result[j-1] * post_mul;
        }
        return result;
    }
};
// @lc code=end

