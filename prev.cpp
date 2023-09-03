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
    int ans = 0;
    int finale;
    int ct = 0;
    bool flag = false;
    void recurse(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        if (flag) return;
        recurse(root->left);
        ct++;
        if (ct == finale) {
            ans = root->val;
            flag = true;
            return;
        }
        recurse(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        finale = k;
        recurse(root);
        return ans;
    }
};
    bool isEven = ct % 2 == 0;
    cin >> m;
    // queries
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        if (((r-l+1)/2) % 2 == 1) {
            isEven = !isEven;
        }
        if (isEven) {
            cout << "even\n";
        } else {
            cout << "odd\n";
        }
    }
}





