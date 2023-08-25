/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    bool flag = false;
    int recurse(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return 0;
        int l = recurse(root->left, p, q);
        int r = recurse(root->right, p, q);
        int s = l + r;
        if (root == p || root == q) {
            s++;
        }
        if (s >= 2) {
            ans = root;
        }
        return s > 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recurse(root, p, q);
        return ans;
    }
};
