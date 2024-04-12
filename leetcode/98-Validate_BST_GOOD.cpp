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
            bool recurse(TreeNode* root, TreeNode* small, TreeNode* big) {
                        if (!root) return true;
                                if ((small && root->val <= small->val) || big && root->val >= big->val)
                                                return false;
                                        return recurse(root->left, small, root) && recurse(root->right, root, big);
                                            }
                bool isValidBST(TreeNode* root) {
                            return recurse(root, nullptr, nullptr);
                                }
};
