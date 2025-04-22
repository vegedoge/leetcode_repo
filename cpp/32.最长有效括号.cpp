/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int result = 0;
        // init all to 0
        vector<int>dp(n + 1, 0);

        for (int i = 1; i < n; i++) {
            // ()(())()
            if(s[i] == ')') {
                if(s[i-1] == '(') {
                    // ...()
                    if(i-2 > 0) {
                        dp[i] = dp[i - 2] + 2;
                    } else {
                        dp[i] = 2;
                    } 
                } else if(dp[i-1] > 0) {
                    // () (())
                    if (i-1 - dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(') {
                        if (i-1-dp[i-1]-1 > 0) {
                            dp[i] = dp[i - 1] + dp[i - 1 - dp[i - 1] - 1] + 2;
                        } else {
                            dp[i] = dp[i - 1] + 2;
                        }
                    }
                }
            }
            result = max(result, dp[i]);
        }

        return result;
    }
};
// @lc code=end

