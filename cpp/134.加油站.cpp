/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include<vector>
// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        

        // 暴力模拟会超时

        // int cur_gas = 0;
        // int n = gas.size();
        // int start = 0;
        // int cur_idx = 0;
        // while (start < n)
        // {
        //     cur_idx = start;
        //     cur_gas = gas[cur_idx];
        //     while (cur_gas >= cost[cur_idx]) {
        //         cur_gas -= cost[cur_idx];
        //         cur_idx = (cur_idx + 1) % n;
        //         if (cur_idx == start) {
        //             return start;
        //         }

        //         cur_gas += gas[cur_idx];
        //     }
        //     start++;
        // }

        // return -1;

        // 计算总消耗和总输入
        int total_gas = 0;
        int total_surplus = 0;
        int start = 0;

        for (int i = 0; i < gas.size(); ++i) {
            int cur_gas = gas[i] - cost[i];
            total_gas = total_gas + cur_gas;
            total_surplus += cur_gas;

            // 如果这里没成功 从下一个重新开始尝试
            if (total_gas < 0) {
                start = i + 1;
                total_gas = 0;
            }
        }

        return total_surplus >= 0 ? start : -1;
    }
};
// @lc code=end

