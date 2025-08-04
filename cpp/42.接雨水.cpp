/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);

        max_left[0] = height[0];
        max_right[n - 1] = height[n - 1];

        for (int i = 1; i < n; ++i) {
            max_left[i] = max(height[i], max_left[i - 1]);
        }

        for (int j = n - 2; j > -1; --j) {
            max_right[j] = max(height[j], max_right[j + 1]);
        }

        int result = 0;
        for (int i = 1; i < n - 1; ++i) {
            int limit = min(max_left[i], max_right[i]);
            if (limit > height[i]) {
                result += limit - height[i];
            }
        }

        return result;
    }
};
// @lc code=end

