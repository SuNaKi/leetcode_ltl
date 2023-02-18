/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
 bool cmp(TreeNode* l,TreeNode* r){
        if (l == nullptr && r != nullptr) return false;
        else if (l != nullptr && r == nullptr) return false;
        else if (l == nullptr && r == nullptr) return true;
        else if (l->val != r->val) return false;
        bool o = cmp(l->left,r->right);
        bool i = cmp(l->right,r->left);
        return o&&i;
    }
    bool isSymmetric(TreeNode* root) {
        return cmp(root->left, root->right);
    }
   
};
// @lc code=end

