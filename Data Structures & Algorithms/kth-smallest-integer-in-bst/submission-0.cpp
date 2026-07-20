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
        vector<int> res;
        res.reserve(k);
        dfs(root, res);
        return res[k - 1];
    }

    void dfs(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        dfs(root->left, arr);
        arr.push_back(root->val);
        dfs(root->right, arr);
        return;
    }
};
