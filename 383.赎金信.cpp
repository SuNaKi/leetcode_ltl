/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int rec[26] ={0};
        if (magazine.size() < ransomNote.size()){
            return false;
        }
        for (int i = 0; i < magazine.size();i++){
            rec[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++){
            rec[ransomNote[i] - 'a']--;
        }
        for (auto i : rec){
            if(i < 0) return false;
        }
        return true;
    }
};
// @lc code=end

