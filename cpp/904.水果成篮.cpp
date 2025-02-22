/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        int result = 0;
        int sub_len = 0;
        unordered_map<int, int> baskets;

        for (; right < fruits.size(); right++) {
            baskets[fruits[right]]++;

            while(baskets.size() > 2) {
                baskets[fruits[left]]--;
                if (baskets[fruits[left]] == 0) {
                    baskets.erase(fruits[left]);
                }
                left++;
            }
            // remember the length should add one
            sub_len = right - left + 1;
            result = result > sub_len ? result : sub_len;
        }
        return result;
    }
};
// @lc code=end

