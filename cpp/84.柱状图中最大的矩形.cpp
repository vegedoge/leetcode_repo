/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include <stack>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        std::vector<int> new_heights(n + 2, 0);

        // 左右各来一个哨兵0
        for (int i = 0; i < n; ++i) {
            new_heights[i + 1] = heights[i];
        }

        // 存放idx
        stack<int> mono_stack;
        int max_area = 0;

        for (int i = 0; i < n + 2; ++i) {
            while (!mono_stack.empty() && new_heights[i] < new_heights[mono_stack.top()]) {
                int height = new_heights[mono_stack.top()];
                mono_stack.pop();
                int left_boundary = mono_stack.top();
                int right_boundary = i;

                int width = right_boundary - left_boundary - 1;

                max_area = max(max_area, width * height);
            }
            mono_stack.push(i);
        }

        return max_area;
    }
};
// @lc code=end

