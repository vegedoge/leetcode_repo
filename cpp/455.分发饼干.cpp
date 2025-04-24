/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */
#include<vector>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());

        int result = 0;
        int index = 0;
        if (s.size() == 0) {
            return 0;
        }
        for (int i = 0; i < g.size(); i++)
        {
            if (s[index] >= g[i]) {
                index++;
                result++;
                if (index == s.size())
                {
                    return result;
                }
            }
        }

        return result;
    }
};
// @lc code=end

