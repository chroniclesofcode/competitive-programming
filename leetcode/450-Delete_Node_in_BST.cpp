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
    TreeNode* head;
    void insert(TreeNode* root, int val, TreeNode* add) {
        if (root == NULL) {
            head = add;
            return;
        }
        if (val < root->val) {
            if (root->left == NULL) {
                root->left = add;
            } else {
                insert(root->left, val, add);
            }
        } else if (val > root->val) {
            if (root->right == NULL) {
                root->right = add;
            } else {
                insert(root->right, val, add);
            }
        }
    }

    void dfs(TreeNode* root, TreeNode* par, int key) {
        if (root == NULL) return;
        if (key < root->val) {
            dfs(root->left, root, key);
        } else if (key > root->val) {
            dfs(root->right, root, key);
        } else if (key == root->val) {
            if (par != NULL) {
                if (root->val < par->val) {
                    par->left = NULL;
                } else if (root->val > par->val) {
                    par->right = NULL;
                }
            } else {
                head = NULL;
            }
            if (root->left != NULL) insert(head, root->left->val, root->left);
            if (root->right != NULL) insert(head, root->right->val, root->right);
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       if (root == NULL) return NULL;
        head = root;
        dfs(root, NULL, key);
        return head;
    }
};