/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<string>> results;
    vector<string> temp_result;

    void backTracking(string s, int startIndex) {
        if (startIndex >= s.size()) {
            results.push_back(temp_result);
            return;
        } else {
            for (int i = startIndex; i < s.size(); ++i) {
                if (isPalindrome(s, startIndex, i)) {
                    string sub_str = s.substr(startIndex, i - startIndex + 1);
                    temp_result.push_back(sub_str);
                } else {
                    continue;
                }

                backTracking(s, i + 1);
                temp_result.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (!(s[i] == s[j])) {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> partition(string s)
    {
        results.clear();
        temp_result.clear();
        backTracking(s, 0);

        return results;
    }
};
// @lc code=end

