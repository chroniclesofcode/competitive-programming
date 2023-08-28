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
    unordered_map<int, int> piv;
    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder, int l, int r, int& idx) {
        if (l > r) {
            return NULL;
        }
        // Finds inorder index corresponding to preorder index
        int val = preorder[idx++];
        int mid = piv[val];
        TreeNode* add = new TreeNode(val);
        add->left = recurse(preorder,inorder,l,mid-1,idx);
        add->right = recurse(preorder,inorder,mid+1,r,idx);
        return add;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            piv[inorder[i]] = i;
        }
        int rt = 0;
        return recurse(preorder, inorder, 0, inorder.size()-1, rt);
    }
};
