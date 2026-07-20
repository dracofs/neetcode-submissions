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
    vector<int> rightSideView(TreeNode* root) {
        // level order traversal, for each level push the node in back of queue
        vector<int> res;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()) {
            int size = q.size();
            // get rightmost node
            TreeNode* right = q.back();
            res.push_back(right->val);

            // process level order;
            for (int i = 0; i < size; i++) {
                TreeNode* top = q.front();
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
                q.pop();
            }
        }

        return res;
    }
};
