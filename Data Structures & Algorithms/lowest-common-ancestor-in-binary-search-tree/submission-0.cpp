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
    pair<TreeNode*, bool> find(TreeNode *root, TreeNode *a, TreeNode *b, pair<bool, bool>& seen) {
        
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;

        if (q->val < p->val) swap(q, p);

        if (root->val < p->val) return lowestCommonAncestor(root->right, p, q); // look in right subtree
        if (root->val > q->val) return lowestCommonAncestor(root->left, p, q); // look in left subtree
        
        return root;
    }
};
