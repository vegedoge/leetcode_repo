/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<char> result;
    bool hit;
    void backTracking(vector<vector<char>> &board, vector<vector<bool>>& tags, string word, int wordIndex, int x, int y)
    {
        // check visited
        if (tags[x][y]) {
            return;
        }

        // mark visited
        tags[x][y] = true;

        if (board[x][y] == word[wordIndex]) {

            if (wordIndex + 1 == word.size())
            {
                hit = true;
                return;
            }

            if (x - 1 >= 0 && !hit)
            {
                backTracking(board, tags, word, wordIndex + 1, x - 1, y);
            }
            if (y - 1 >= 0 && !hit) {
                backTracking(board, tags, word, wordIndex + 1, x, y -1);
            }
            if (x + 1 < board.size() && !hit)
            {
                backTracking(board, tags, word, wordIndex + 1, x + 1, y);
            }
            if (y + 1 < board[0].size() && !hit) {
                backTracking(board, tags, word, wordIndex + 1, x, y + 1);
            }

        }

        tags[x][y] = false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> tags(board.size(), vector<bool>(board[0].size(), false));
        hit = false;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++) {
                backTracking(board, tags, word, 0, i, j);
                if (hit) {
                    return true;
                }
            }
        }

        return false;
    }
};

// a b c e
// s f c s
// a d e e
// @lc code=end

