/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int steps = 0;
        int local_max = 0;
        int end = 0;    // 上次跳跃的右边界
        
        for (int i = 0; i < nums.size() - 1; i++) {
            local_max = max(local_max, nums[i] + i);
            // 相当于每次在一个区间里找能跳的最远距离
            if(i == end) {
                steps++;
                end = local_max;
            }
        }
        return steps;
    }
};
// @lc code=end

