/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <string>
#include <vector>
// @lc code=start
class Solution {
private:
    std::vector<std::string> results;
    std::string temp;
    void backTracking(int& left, int& right) {
        if (left == 0 && right == 0) {
            results.emplace_back(temp);
            return;
        }

        if (left > 0) {
            left--;
            temp += "(";
            backTracking(left, right);
            temp.pop_back();
            left++;
        }

        if (right > left) {
            right--;
            temp += ")";
            backTracking(left, right);
            temp.pop_back();
            right++;
        }
    }

public:
    std::vector<std::string> generateParenthesis(int n) {
        results.clear();
        int left = n;
        int right = n;
        backTracking(left, right);
        return results;
    }
};
// @lc code=end

