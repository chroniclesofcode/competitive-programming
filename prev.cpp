/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;

        Node *curr = root;
        Node *prev = NULL;
        while (curr) {
            Node *first = curr->left ? curr->left : curr->right;
            if (prev) {
                prev->next = first;
            }
            if (first) {
                prev = first;
            }
            if (prev && curr->left && curr->right) {
                prev->next = curr->right;
                prev = curr->right;
            }
            curr = curr->next;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};
/*
*/