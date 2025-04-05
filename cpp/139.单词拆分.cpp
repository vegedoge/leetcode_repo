/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 前i个是否可以拆
        vector<bool> dp(s.size()+1, false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dp[0] = true;
        int flag = false;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                flag = false;
                // 前面能拆，后面也能找到
                if (dp[j])
                {
                    if(dict.find(s.substr(j, i-j)) != dict.end()) {
                        flag = true;
                        break;
                    }
                }
            }
            dp[i] = flag;
        }
        return dp[s.size()];
    }
};
// @lc code=end

