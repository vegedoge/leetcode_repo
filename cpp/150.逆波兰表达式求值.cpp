/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include<vector>
#include<string>
#include<stack>
// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> inputs;
        int lhs;
        int rhs;
        for (auto& token : tokens)
        {
            if(isNumber(token)) {
                inputs.push(std::stoi(token));
            } else {
                std::pair<int, int> operands = get_operands(inputs);

                if (token == "+") {
                    inputs.push(operands.first + operands.second);
                } else if (token == "-") {
                    inputs.push(operands.first - operands.second);
                } else if (token == "*") {
                    inputs.push(operands.first * operands.second);
                } else if (token == "/") {
                    inputs.push(operands.first / operands.second);
                } else {
                    printf("wrong input");
                }
            }
        }
        return inputs.top();
    }

    std::pair<int, int> get_operands(std::stack<int>& inputs) {
        int lhs;
        int rhs;
        rhs = inputs.top();
        inputs.pop();
        lhs = inputs.top();
        inputs.pop();
        return {lhs, rhs};
    }

    bool isNumber(std::string& token) {
        if(token.empty()) {
            return false;
        }
        size_t i = 0;
        if (token[0] == '-')
        {
            i++;
            if (token.size() == 1)
            {
                return false;
            }
        }
        for (; i < token.size();i++) {
            if(!isdigit(token[i])) {
                return false;
            }
        }

            return true;
    }
};
// @lc code=end

