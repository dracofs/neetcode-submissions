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
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }

    int countGoodNodes(TreeNode* root, int maxSeen) {
        if (!root) return 0;
        int res = 0;
        if (root->val >= maxSeen) res++;
        maxSeen = max(maxSeen, root->val);
        return res + countGoodNodes(root->left, maxSeen) + countGoodNodes(root->right, maxSeen);
    }
};
