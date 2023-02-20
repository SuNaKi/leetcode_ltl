/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int l = 0, r = 0;
        l = sumOfLeftLeaves(root->left);
        if (root->left && root->left->left == nullptr && root->left->right == nullptr)
        {
            l = root->left->val;
        }
        r = sumOfLeftLeaves(root->right);
        return l + r;
        
    }
};
// @lc code=end

