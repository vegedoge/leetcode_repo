/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include<algorithm>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int local_sum;
        int left, right;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            // early cutoff
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            left = i + 1;
            right = nums.size() - 1;
            while (left < right)
            {
                local_sum = nums[i] + nums[left] + nums[right];
                if (local_sum == 0) {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // remove the same sets
                    while(right > left && nums[right] == nums[right-1])
                        right--;
                    while(right > left && nums[left] == nums[left + 1])
                        left++;
                    // move the pointers
                    right--;
                    left++;
                }
                else if (local_sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return result;
    }
};
// @lc code=end

