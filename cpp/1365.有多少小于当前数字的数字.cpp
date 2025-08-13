/*
 * @lc app=leetcode.cn id=1365 lang=cpp
 *
 * [1365] 有多少小于当前数字的数字
 */
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> hash(101);
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        // 倒序保证只存相同数字里最左边的数的idx
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            hash[temp[i]] = i;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            temp[i] = hash[nums[i]];
        }
        return temp;
    }
};
// @lc code=end

