/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int end1 = matrix.size();
        int end2 = matrix[0].size();
        int n = matrix[0].size();

        int start1 = 0;
        int start2 = 0;

        while(start1 < end1) {
            int mid1 = (start1 + end1) / 2;
            if (matrix[mid1][0] == target || matrix[mid1][n - 1] == target) {
                return true;
            }
            if (matrix[mid1][0] < target && matrix[mid1][n-1] > target) {
                while(start2 < end2) {
                    int mid2 = (start2 + end2) / 2;
                    if (matrix[mid1][mid2] == target) {
                        return true;
                    } else if (matrix[mid1][mid2] > target) {
                        end2 = mid2;
                    } else {
                        start2 = mid2 + 1;
                    }
                }
                return false;
            }
            else if (matrix[mid1][0] > target)
            {
                end1 = mid1;
            }
            else if (matrix[mid1][n - 1] < target)
            {
                start1 = mid1 + 1;
            }
        }

        return false;
    }
};
// @lc code=end

