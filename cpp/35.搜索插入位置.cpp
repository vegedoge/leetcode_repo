/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle;

        while (left < right) {
            middle = left + (right - left) / 2;

            if (nums[middle] > target) {
                right = middle;
            }
            else if (nums[middle] == target) {
                return middle;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
};
// @lc code=end

