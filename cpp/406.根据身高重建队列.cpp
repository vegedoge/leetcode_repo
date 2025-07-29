/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include<list>
#include<vector>
#include<algorithm>
using namespace std;
// @lc code=start
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> queue;

        for (int i = 0; i < people.size(); ++i) {
            int pos = people[i][1];

            list<vector<int>>::iterator it = queue.begin();
            while(pos--) {
                it++;
            }

            queue.insert(it, people[i]);
        }

        return vector<vector<int>>(queue.begin(), queue.end());
    }
};
// @lc code=end

