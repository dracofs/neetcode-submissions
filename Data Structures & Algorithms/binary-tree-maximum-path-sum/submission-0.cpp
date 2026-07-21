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
    int maxPathSum(TreeNode* root) {
        if (!root) return 0;

        int best = root->val;
        dfs(root, best);
        return best;
    }

    int dfs(TreeNode* root, int& best) {
        if (!root) return 0;

        int left = max(dfs(root->left, best), 0);
        int right = max(dfs(root->right, best), 0);
        
        best = max(best, left + right + root->val);
        return root->val + max(left, right); 
    }
};
