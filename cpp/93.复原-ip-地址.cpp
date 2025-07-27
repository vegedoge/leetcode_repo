/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include<vector>
#include<string>
#include<algorithm>
// @lc code=start
class Solution {
public:
    std::vector<std::string> results;
    std::vector<std::string> temp_result;

    std::vector<std::string> restoreIpAddresses(std::string s)
    {
        results.clear();
        temp_result.clear();
        backTracking(s, 0);

        return results;
    }

    bool validAddressSeg(const std::string& s, int start, int end) {
        if (start > end || start < 0 || end > s.size())
            return false;

        if (end - start > 3) {
            return false;
        }
        if (start != end && s[start] == '0')
        {
            return false;
        }
        else
        {
            std::string str = s.substr(start, end - start + 1);

            if (str.empty()) {
                return false;
            }
            int val = std::stoi(str);

            if (val > 255) {
                return false;
            }
        }

        return true;
    }

    std::string genIpAddress(const std::vector<std::string>& s) {
        std::string ip_addr;

        for (auto str: s) {
            ip_addr += str;
            ip_addr += '.';
        }
        // remove '.'
        ip_addr.pop_back();
        return ip_addr;
    }

    void backTracking(std::string s, int startIndex) {
        if (temp_result.size() == 3) {
            if (validAddressSeg(s, startIndex, s.size() - 1)) {
                temp_result.push_back(s.substr(startIndex, s.size() - startIndex));
                results.push_back(genIpAddress(temp_result));
                temp_result.pop_back();
            }
            return;
        } else {
            for (int i = startIndex; i < s.size() && i < startIndex + 3; ++i) {
                if (validAddressSeg(s, startIndex, i)) {
                    std::string seg = s.substr(startIndex, i - startIndex + 1);
                    temp_result.push_back(seg);
                } else {
                    continue;
                }

                backTracking(s, i + 1);
                temp_result.pop_back();
            }
        }
    }
};
// @lc code=end

