/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> rows(9);
        vector<unordered_set<int>> cols(9);
        vector<unordered_set<int>> areas(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char val_c = board[i][j];
                int val;
                if (val_c == '.')
                {
                    continue;
                }
                else
                {
                    val = val_c - '0';
                }
                if (rows[i].count(val)) {
                    return false;
                } else {
                    rows[i].insert(val);
                }

                if (cols[j].count(val)) {
                    return false;
                } else {
                    cols[j].insert(val);
                }

                int area_idx = 3 * (i / 3) + (j / 3);
                if (areas[area_idx].count(val)) {
                    return false;
                } else {
                    areas[area_idx].insert(val);
                }
            }
        }

        return true;
    }
};
// @lc code=end

