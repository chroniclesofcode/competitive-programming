/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL) return "";
        string ser;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* u = q.front();
            q.pop();
            if (u == NULL) {
                ser += "N,";
                continue;
            } else {
                ser += to_string(u->val);
                ser += ",";
            }
            q.push(u->left);
            q.push(u->right);
        }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "") {
            return NULL;
        }
        string tmp = "";
        queue<TreeNode*> q;
        int i = 0;
        int n = data.size();
        while (i < n && data[i] != ',') {
            tmp += data[i];
            i++;
        }
        i++;
        TreeNode* head = new TreeNode(stoi(tmp));
        q.push(head);
        tmp = "";
        while (!q.empty() && i < n) {
            int sz = q.size();
            // iterate through queue, for each node, pop 2 from data
            for (int z = 0; z < sz; z++) {
                TreeNode* add = q.front();
                q.pop();
                if (add == NULL) continue;
                tmp = "";
                // left node
                while (i < n && data[i] != ',') {
                    tmp += data[i];
                    i++;
                }
                i++;
                if (tmp == "N") {
                    add->left = NULL;
                } else {
                    add->left = new TreeNode(stoi(tmp));
                    q.push(add->left);
                }
                tmp = "";
                // Right node
                while (i < n && data[i] != ',') {
                    tmp += data[i];
                    i++;
                }
                i++;
                if (tmp == "N") {
                    add->right = NULL;
                } else {
                    add->right = new TreeNode(stoi(tmp));
                    q.push(add->right);
                }
                tmp = "";
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
