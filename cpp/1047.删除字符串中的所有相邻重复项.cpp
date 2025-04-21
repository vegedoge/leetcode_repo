/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */
#include<stack>
#include<string>
#include<algorithm>
// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        std::string ret;
        std::stack<char> results;
        for(char c: s) {
            if(!results.empty()) {
                if(results.top() == c) {
                    results.pop();
                    continue;
                }
            }
            results.push(c);
        }
        while(!results.empty()) {
            ret.push_back(results.top());
            results.pop();
        }
        std::reverse(ret.begin(), ret.end());

        return ret;
    }
};
// @lc code=end

