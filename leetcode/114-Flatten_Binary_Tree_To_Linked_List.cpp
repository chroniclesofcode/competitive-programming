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
    TreeNode *head;
    TreeNode *tail;
    void dfs(TreeNode *root) {
        if (root == nullptr) return;

        if (head == nullptr) {
            head = new TreeNode(root->val);
            tail = head;
        } else {
            tail->right = new TreeNode(root->val);
            tail = tail->right;
        }

        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        if (head != nullptr) {
            *root = *head;
        }
    }
};
