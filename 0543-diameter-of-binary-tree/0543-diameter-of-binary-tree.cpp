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
    int maxdiameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        calculateheight(root);
        return maxdiameter;
    }

    int calculateheight(TreeNode* node) {
        if (!node)
            return 0;

        int left_height = calculateheight(node->left);
        int right_height = calculateheight(node->right);
        maxdiameter = max(maxdiameter, left_height + right_height);

        return 1 + max(left_height, right_height);
    }
};