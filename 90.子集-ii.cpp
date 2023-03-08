/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &nums, int startIndex, vector<bool> &used)
    {
        res.push_back(path);
        for (size_t i = startIndex; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            dfs(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, used);
        return res;
    }
};
// @lc code=end
