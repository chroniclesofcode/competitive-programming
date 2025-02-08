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
        TreeNode* l = root->left;
        TreeNode* r = root->right;

        if (head == nullptr) {
            head = root;
            tail = head;
            head->left = nullptr;
            head->right = nullptr;
        } else {
            tail->right = root;
            tail->left = nullptr;
            tail = tail->right;
        }

        dfs(l);
        dfs(r);
    }
    void flatten(TreeNode* root) {
        dfs(root);
    }
};
