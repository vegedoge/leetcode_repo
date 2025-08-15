/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    // 顺时针90°：转置 + 水平镜像
    // 逆时针90°：转置 + 垂直镜像
    // 180°：水平镜像 + 垂直镜像
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            // 注意这里j < i
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0, k = matrix.size() - 1; j < k; ++j, --k) {
                swap(matrix[i][j], matrix[i][k]);
            }
        }
        
    }
};
// @lc code=end

