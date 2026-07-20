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
    int dfs(TreeNode* root, int& curr) {
        if (!root) return 0;
        int left = dfs(root->left, curr);
        int right = dfs(root->right, curr);
        curr = max(curr, left + right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};
