/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> squared_nums(right + 1);
        int index = right;

        while (left <= right)
        {
            int right_2 = nums[right] * nums[right];
            int left_2 = nums[left] * nums[left];

            if (right_2 >= left_2) {
                squared_nums[index--] = right_2;
                right--;
            } else {
                squared_nums[index--] = left_2;
                left++;
            }
        }
        return squared_nums;
    }
};
// @lc code=end

