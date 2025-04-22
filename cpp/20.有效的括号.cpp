/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include<string>
#include<stack>

// @lc code=start
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (const auto& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (stack.empty()) return false; 
                char top = stack.top();
                if ((c == ')' && top != '(') || 
                    (c == ']' && top != '[') || 
                    (c == '}' && top != '{')) {
                    return false; 
                }
                stack.pop(); 
            }
        }
        return stack.empty(); 
    }
};
// @lc code=end

