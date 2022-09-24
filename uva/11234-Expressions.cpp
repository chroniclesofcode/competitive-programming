#include <bits/stdc++.h>

using namespace std;

#define LL long long

void solve();

// build a tree and level order traverse it.
typedef struct Node {
    char val;
    Node *left;
    Node *right;
} Node;

stack<Node*> s;

int main(void) {
    cin.tie(nullptr);
    cin.sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
   
}

// Make expression tree, then level order traversal
// reverse the string and you will have it (cuz ur going from
// bottom to top).
// Note, since the question says the expressions are not associative
// or commutative, you have to actually flip the left and right
// nodes to get the correct ans as a queue does the reverse.


void solve() {  
    string p;
    cin >> p;

    Node *head = NULL;
    for (int i = 0; i < p.length(); i++) {
        Node *n = new Node;
        n->val = p[i];
        if (isupper(p[i])) {
            Node *one = s.top();
            s.pop();
            Node *two = s.top();
            s.pop();

            n->left = two;
            n->right = one;

            s.push(n);
            head = n;
        } else {
            // Create node
            n->left = NULL;
            n->right = NULL;
            s.push(n);
        }
    }

    string res;
    queue<Node*> q;
    q.push(head);
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node* f = q.front();
            if (f->left != NULL)
                q.push(f->left);
            if (f->right != NULL)
                q.push(f->right);
            res.push_back(f->val);
            q.pop();
        }
    }

    reverse(res.begin(), res.end());
    cout << res << endl;
}

// Operations

// S xPy, zIw, xPyMzIw

// Q wIz, yPx, wIzMyPx
    
/*

S: 
    a b c
    a cAb
    cAbBa
    cAbBa d e f g
    cAbBa d e gCf
    cAbBa d gCfDe
    cAbBa gCfDeEd
    gCfDeEdFcAbBa 

Q:

   g f
   gCf
   gCf e c b 
   c b gCfDe
   c b gCfDe d
   gCfDe d cAb
   gCfDe d cAb a
   cAb a gCfDeEd
   gCfDeEd cAbBa
   gCfDeEdFcAbBa


*/


