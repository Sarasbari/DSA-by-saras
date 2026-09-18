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
    bool isValidBST(TreeNode* root) {
        return isBST(root, LLONG_MIN, LLONG_MAX);
    }

    bool isBST(TreeNode* node, long minval, long maxval) {
        if (!node)
            return true;
        if (node->val >= maxval || node->val <= minval)
            return false;
        return (isBST(node->left, minval, node->val) &&
                isBST(node->right, node->val, maxval));
    }
};