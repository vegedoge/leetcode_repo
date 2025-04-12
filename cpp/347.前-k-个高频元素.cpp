/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
// @lc code=start
class Solution {
public:
    // min-heap
    class myComp {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++ ) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp> pri_queue;

        // use min-heap of size k to scan all the frequency
        // min-heap access smaller elements first
        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            pri_queue.push(*it);
            if (pri_queue.size() > k) {
                pri_queue.pop();
            }
        }

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            result[i] = pri_queue.top().first;
            pri_queue.pop();
        }
        return result;
    }
};
// @lc code=end

