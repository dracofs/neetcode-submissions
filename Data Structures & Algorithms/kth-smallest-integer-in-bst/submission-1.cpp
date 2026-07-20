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
    int kthSmallest(TreeNode* root, int k) {
        // dfs left tree to try to find k,
        // else look for k - (num elements in left subtree)
        pair<int, bool> res;
        int acc = 0;
        dfs(root, k, acc, res);
        return res.first;
    }

    void dfs(TreeNode* root, int k, int& acc, pair<int, bool>& res) {
        if (!root) return;
        dfs(root->left, k, acc, res);
        acc++;
        if (acc == k) {
            res = {root->val, true};
            return;
        }
        dfs(root->right, k, acc, res);
    }
};
