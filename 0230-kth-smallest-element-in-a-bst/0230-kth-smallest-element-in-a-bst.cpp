/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root)
            return 0;
        func(root, k);
        return ans;
    }

    int ans = 0, cnt = 0;

    void func(TreeNode* root, int k) {
        if (!root)
            return;

        if (root->left) {
            func(root->left, k);
        }
        cnt++;

        if (cnt == k) {
            ans = root->val;
            return;
        } else if (root->right)
            func(root->right, k);
        return;
    }
};