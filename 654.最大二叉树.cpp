/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    TreeNode* node = new TreeNode(0);
    if (nums.size() == 1)
    {
        /* code */
        node->val = nums[0];
        return node;
    }
    int maxV = 0, id = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        if (nums[i] > maxV)
        {
            maxV = nums[i];
            id = i;
        }
    }
    node->val = maxV;
    if (id > 0)
    {
        vector<int> nV(nums.begin(), nums.begin() + id);
        node->left = constructMaximumBinaryTree(nV);
    }
    if (id < (nums.size() - 1))
    {
        vector<int> nV(nums.begin() + id + 1, nums.end());
        node->right = constructMaximumBinaryTree(nV);
    }
    return node;
    
    }
};
// @lc code=end

