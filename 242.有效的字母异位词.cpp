/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int hash[26] = {0};
        for (int i = 0; i < s.length(); i++)
            hash[s[i]-'a']++;
        for (int i = 0; i < t.length(); i++)
            hash[t[i]-'a']--;
        for (int i = 0; i < 26; i++)
        if (hash[i] != 0) return false;
        return true;
    }

};
// @lc code=end

