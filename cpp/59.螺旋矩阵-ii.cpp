/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        // edge value of the four edges
        int top = 0, right = n - 1;
        int left = 0, bottom = n - 1;
        int count = 1;

        while (count <= n * n) {
            for (int i = left; i <= right; i++) {
                result[top][i] = count++;
            }
            top++;

            for (int j = top; j <= bottom; j++) {
                result[j][right] = count++;
            }
            right--;

            for (int k = right; k >= left; k--) {
                result[bottom][k] = count++;
            }
            bottom--;

            for (int z = bottom; z >= top; z--) {
                result[z][left] = count++;
            }
            left++;
        }
        return result;
    }
};
// @lc code=end

