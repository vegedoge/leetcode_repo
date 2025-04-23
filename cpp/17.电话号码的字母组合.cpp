/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include<vector>
#include<string>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> results;
    string temp;

    const string str_mapping[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

    void backTracking(const string& digits, int startIndex) {
        if(startIndex == digits.size()) {
            results.push_back(temp);
            return;
        }

        int digit = digits[startIndex] - '0';
        string letters = str_mapping[digit];

        for (int i = 0; i < letters.size(); i++) {
            temp += letters[i];
            backTracking(digits, startIndex + 1);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        temp.clear();
        results.clear();
        if (digits.size() == 0)
        {
            return results;
        }

        backTracking(digits, 0);
        return results;
    }
};
// @lc code=end

