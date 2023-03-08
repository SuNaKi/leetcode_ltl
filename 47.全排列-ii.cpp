/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && false == used[i - 1])
            {
                continue;
            }
            if (true == used[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used);
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};
// @lc code=end
