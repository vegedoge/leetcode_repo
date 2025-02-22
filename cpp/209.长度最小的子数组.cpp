/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int end = 0;
        int sum = 0;
        int len = __INT32_MAX__;
        int sub_len = 0;

        for (; end < nums.size(); end++)
        {
            sum += nums[end];
            while (sum >= target)
            {
                sub_len = end - start + 1;
                len = sub_len < len ? sub_len : len;
                sum -= nums[start];
                start++;
            } 
        }
        return len == __INT32_MAX__ ? 0 : len;
    }
};
// @lc code=end

