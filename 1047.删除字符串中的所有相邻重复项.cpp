/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (auto i:s){
            if (res.empty() || i != res.back())
            res.push_back(i);
            else res.pop_back();
        }
        return res;
    }
};
// @lc code=end

