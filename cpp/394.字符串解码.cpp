/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include<string>
#include<stack>
using namespace std;
// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> local_st;
        string res = "";
        int coeff = 0;
        for(char c: s) {
            if(c - '0' >= 0 && c - '0' <= 9) {
                coeff = coeff * 10 + (c - '0');
            } else if ( c >= 'a' && c <= 'z') {
                res.push_back(c);
            } else if (c == '[') {
                pair<int, string> st2(coeff, res);
                local_st.push(st2);
                res = "";
                coeff = 0;
            } else if(c == ']') {
                pair<int, string> st3 = local_st.top();
                local_st.pop();
                coeff = st3.first;
                string cated_res = st3.second;
                while(coeff>0) {
                    cated_res.append(res);
                    coeff--;
                }
                res = cated_res;
            }
        }
        return res;
    }
};
// @lc code=end

