/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include<vector>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> prev_temp;
        vector<int> result(temperatures.size(), 0);
        for (int i = 0; i < temperatures.size(); i++)
        {
            pair<int, int> temp(i, temperatures[i]);
            if (prev_temp.empty())
            {
                prev_temp.push(temp);
            }
            else
            {
                while(temp.second > prev_temp.top().second) {
                    int index = prev_temp.top().first;
                    result[index] = i - index;
                    prev_temp.pop();
                    if (prev_temp.empty()) {
                        break;
                    }
                }
                prev_temp.push(temp);
            }
        }
        return result;
    }
};
// @lc code=end

