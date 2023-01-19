/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int count = 0;
        unordered_map<int,int> map;
        for (auto a : nums1){
            for (auto b : nums2){
                map[a + b] ++;
            }
        }
        for (auto c : nums3){
            for (auto d : nums4){
                int target = 0 - (c + d);
                if ( map.find(target) != map.end()){
                    count += map[target];
                }
            }
        }
        return count;
    }
};
// @lc code=end

