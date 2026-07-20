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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p) return !q;
        if (!q) return !p;

        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return !subRoot;
        bool left = isSubtree(root->left, subRoot); // O(n)
        bool right = isSubtree(root->right, subRoot); //O(n)
        if (right || left) return true;
        else return isSameTree(root, subRoot);
    }
};
