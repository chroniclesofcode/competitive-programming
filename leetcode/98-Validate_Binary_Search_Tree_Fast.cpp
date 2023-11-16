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
    long long prev = -LLONG_MAX;
    bool recurse(TreeNode* root) {
        if (root == NULL) return true;
        bool l = recurse(root->left);
        if (root->val <= prev) return false;
        prev = root->val;
        bool r = recurse(root->right);
        return l && r;
    }
    bool isValidBST(TreeNode* root) {
        return recurse(root);
    }
};
