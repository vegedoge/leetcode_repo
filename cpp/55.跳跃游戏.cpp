/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        if (nums.size() == 1) {
            return true;
        }

        for (int i = 0; i <= range; ++i) {
            range = max(range, nums[i] + i);
            if (range >= nums.size() - 1) {
                return true;
            } 

        }
        
        return false;
    }
};
// @lc code=end

