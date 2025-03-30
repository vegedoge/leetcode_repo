/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow;
        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> newRow(i+1, 0);
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0) {
                    newRow[j] = 1;
                } else if (j == i) {
                    newRow[j] = 1;
                } else {
                    newRow[j] = lastRow[j - 1] + lastRow[j];
                }
            }
            lastRow = newRow;
        }
        return lastRow;
    }
};
// @lc code=end

