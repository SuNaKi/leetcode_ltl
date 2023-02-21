/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0)
        {
            return nullptr;
        }
        int rootv = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootv);
        if (postorder.size() == 1)
        {
            return root;
        }
        int i = 0;
        for ( i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == rootv)
            break;           
        }
        vector<int> linorder(inorder.begin(), inorder.begin() + i);
        vector<int> rinorder(inorder.begin() + i + 1, inorder.end());
        postorder.resize(postorder.size() - 1);
        vector<int> lpostorder(postorder.begin(), postorder.begin()
+ linorder.size());
        vector<int> rpostorder(postorder.begin() + linorder.size(), postorder.end());
        root->left = buildTree(linorder, lpostorder);
        root->right = buildTree(rinorder, rpostorder);
        return root;
    }
};
// @lc code=end

