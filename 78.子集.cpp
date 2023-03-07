/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, int startIndex)
    {
        res.push_back(path);
        if (startIndex >= nums.size())
        {
            /* code */ return;
        }
        for (size_t i = startIndex; i < nums.size(); i++)
        {
            /* code */
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(nums, 0);
        return res;
    }
};
// @lc code=end
