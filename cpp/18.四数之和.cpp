/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
using namespace std;
#include <algorithm>
// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int local_sum;
        int left, right;
        int size = nums.size();
        // 注意size() 返回的是无符号的size_t
        for (int i = 0; i < size - 3; i++)
        {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < size - 2; j++) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }

                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                left = j + 1;
                right = nums.size() - 1;

                while(left < right) {
                    long local_sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (local_sum < target) {
                        left++;
                    } else if (local_sum > target) {
                        right--;
                    } else {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1])
                            left++;
                        while(left < right && nums[right] == nums[right - 1])
                            right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

