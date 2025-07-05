/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int record = 0;
        int area = 0;
        while (left < right)
        {
            area = std::min(height[right], height[left]) * (right - left);
            if (area > record)
                record = area;

            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }

        return record;
    }
};
// @lc code=end

