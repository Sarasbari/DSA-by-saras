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
    unordered_map<int, int> mp;
    int preIndex = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return fun(preorder, inorder, 0, inorder.size() - 1);
    }

    TreeNode* fun(vector<int>& preorder, vector<int>& inorder, int low,
                  int high) {
        if (low > high) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preIndex++]);
        int in = mp[root->val];
        root->left = fun(preorder, inorder, low, in - 1);
        root->right = fun(preorder, inorder, in + 1, high);
        return root;
    }
};