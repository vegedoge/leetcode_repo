/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include<vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> result;
        int top = 0, right = n - 1;
        int left = 0, bottom = m - 1;
        int count = 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
            }
            top++;

            for (int j = top; j <= bottom; j++) {
                result.push_back(matrix[j][right]);
            }
            right--;

            if (top <= bottom) {
                for (int k = right; k >= left; k--) {
                    result.push_back(matrix[bottom][k]);
                }
                bottom--;
            }

            if (right >= left) {
                for (int z = bottom; z >= top; z--) {
                    result.push_back(matrix[z][left]);
                }
                left++;
            }   
        }
        return result;
    }
};
// @lc code=end

