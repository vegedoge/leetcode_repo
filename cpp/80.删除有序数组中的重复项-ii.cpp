/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        int slow = 2;
        int fast;
        bool full = false;

        for (fast = 2; fast < nums.size(); ++fast)
        {
            if (nums[fast] != nums[slow - 2]) {
                nums[slow] = nums[fast];
                ++slow;
            }
        }

        return slow;
    }
};
// @lc code=end

