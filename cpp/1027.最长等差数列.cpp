/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */
#include <map>
#include <vector>
#include <ranges>
using namespace std;

// @lc code=start
class Solution {
public:
    // 最后两数公差O(N^2)
    // int longestArithSeqLength(vector<int>& nums) {
    //     int n = nums.size();
    //     int result = 0;
    //     map<int, int> max_len[n];

    //     for (int i = 1; i < n; ++i) {
    //         for (int k = 0; k < i; ++k) {
    //             int diff = nums[i] - nums[k];
    //             // 如果前面就有公差为diff的序列
    //             if (max_len[k].count(diff)) {
    //                 max_len[i][diff] = max_len[k][diff] + 1;
    //             }
    //             else
    //             // 如果前面没有，就从2开始
    //             {
    //                 max_len[i][diff] = 2;
    //             }
    //             result = max(max_len[i][diff], result);
    //         }
    //     }

    //     return result;
    // }


    // 枚举公差 O(N * range)
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int max_val = ranges::max(nums);
        int result = 0;

        for (int d = -max_val; d <= max_val; ++d) {
            vector<int> f(max_val + 1, 0);
            for (int x : nums) {
                if (x - d >= 0 && x - d <= max_val) {
                    f[x] = f[x - d] + 1;
                }
                else
                {
                    f[x] = 1;
                }
                result = max(result, f[x]);
            }
        }
        return result;
    }
};
// @lc code=end

