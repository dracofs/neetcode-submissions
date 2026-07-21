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
    int idx = 0;
    unordered_map<int, int> in_idx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) in_idx[inorder[i]] = i;
        return buildTreeH(preorder, 0, preorder.size() - 1);
    }

    TreeNode* buildTreeH(vector<int>& preorder, int l, int r) {
        if (l > r) return 0;
        int val = preorder[idx++];
        TreeNode* root = new TreeNode(val);
        int mid = in_idx[val];
        root->left = buildTreeH(preorder, l, mid - 1);
        root->right = buildTreeH(preorder, mid + 1, r);
        return root;
    }
};
