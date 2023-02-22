/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int cnt = 0, mcnt = 0;
    TreeNode* pre = nullptr;
    vector<int> res;
    void dfs (TreeNode* cur){
        if (cur == nullptr)
        {
            /* code */return ;
        }
        dfs(cur->left);
        if (pre == nullptr)
        {
            cnt = 1;
        }else if (cur->val == pre->val)
        {
            cnt++;
        }else{
            cnt = 1;
        }
        if (cnt == mcnt)
        {
            res.push_back(cur->val);
        }else if (cnt > mcnt)
        {
            res.clear();
            mcnt = cnt;
            res.push_back(cur->val);
        }
        pre = cur;
        dfs(cur->right);
        return ;        
        
    }
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};
// @lc code=end

