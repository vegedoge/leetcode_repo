/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0; // Position to place non-zero elements
        
        // Move all non-zero elements to the front
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                nums[slow++] = nums[fast];
            }
        }
        
        // Fill the rest with zeros
        while (slow < nums.size()) {
            nums[slow++] = 0;
        }
    }
};
// @lc code=end

