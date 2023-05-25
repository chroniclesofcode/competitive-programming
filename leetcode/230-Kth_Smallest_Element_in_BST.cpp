class Solution {
public:
    int ans = 0;
    int ct = 1;
    int flag = 0;
    void rec(TreeNode* root, int k) {
        if (root == NULL || flag) return;
        
        rec(root->left, k);
        if (flag) return;
        if (ct == k) {
            ans = root->val;
            flag = 1;
            return;
        }
        ct++;
        rec(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        rec(root, k);
        return ans;
    }
};
