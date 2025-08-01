/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> left_diagonal;
    unordered_set<int> right_diagonal;
    vector<vector<string>> results;

    void backTracking(vector<string> board, int n, int row) {
        if (row == n) {
            results.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols.count(col))
                continue;
            if (left_diagonal.count(row - col))
                continue;
            if (right_diagonal.count(row + col))
                continue;

            // 不然就是可以选的
            board[row][col] = 'Q';
            cols.insert(col);
            left_diagonal.insert(row - col);
            right_diagonal.insert(row + col);

            backTracking(board, n, row + 1);

            // 回溯
            board[row][col] = '.';
            cols.erase(col);
            left_diagonal.erase(row - col);
            right_diagonal.erase(row + col);
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '.'));
        backTracking(board, n, 0);

        return results;
    }
};
// @lc code=end

