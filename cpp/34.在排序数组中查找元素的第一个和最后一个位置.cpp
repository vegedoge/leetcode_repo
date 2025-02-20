/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle;
        int start = -1 , end = -1;
        

        while (left < right) {
            middle = left + (right - left) / 2;
            
            if (nums[middle] > target) {
                right = middle;
            } 
            else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                start = middle;
                end = middle;
                while (start - 1 > -1 && nums[start - 1] == target ) {
                    start--;
                }
                while (end + 1 < nums.size() && nums[end + 1] == target) {
                    end++;
                }
                return vector<int>{start, end};
            }
        }
        return vector<int>{start, end};
        
    }
};
// @lc code=end

