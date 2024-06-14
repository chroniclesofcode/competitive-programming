#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr LL INF = (LL)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;

class SegmentTreePersistent {
public:
    struct Node {
        Node *l, *r;
        LL sum;

        Node(LL val) : l(nullptr), r(nullptr), sum(val) {}
        Node(Node *l, Node *r) : l(l), r(r), sum(0) {
            if (l) sum += l->sum;
            if (r) sum += r->sum;
        }
    };
    LL ct = 1;
    vector<Node*> trees;

    SegmentTreePersistent(LL maxsz) : trees(maxsz+1) {}

    Node* build(vector<LL> &a, LL tl, LL tr) {
        if (tl == tr)
            return new Node(a[tl]);
        LL tm = (tl + tr) / 2;
        return new Node(build(a, tl, tm), build(a, tm+1, tr));
    }

    LL query(Node* v, LL tl, LL tr, LL l, LL r) {
        if (l > r)
            return 0;
        if (l == tl && tr == r)
            return v->sum;
        LL tm = (tl + tr) / 2;
        return query(v->l, tl, tm, l, min(r, tm))
             + query(v->r, tm+1, tr, max(l, tm+1), r);
    }

    Node* update(Node* v, LL tl, LL tr, LL pos, LL new_val) {
        if (tl == tr)
            return new Node(new_val);
        LL tm = (tl + tr) / 2;
        if (pos <= tm)
            return new Node(update(v->l, tl, tm, pos, new_val), v->r);
        else
            return new Node(v->l, update(v->r, tm+1, tr, pos, new_val));
    }
};
using STP = SegmentTreePersistent;

void solve() {
    LL queries;
    cin >> n >> queries;
    vector<LL> bg(n);
    for (LL i = 0; i < n; i++) {
        cin >> bg[i];
    }
    STP s(MX);
    s.trees[0] = s.build(bg, 0, n-1);
    for (LL q = 0; q < queries; q++) {
        LL op, k, a, b, x; cin >> op;
        if (op == 1) {
            cin >> k >> a >> x; k--; a--;
            s.trees[k] = s.update(s.trees[k], 0, n-1, a, x);
        } else if (op == 2) {
            cin >> k >> a >> b; k--; a--; b--;
            cout << s.query(s.trees[k], 0, n-1, a, b) << '\n';
        } else if (op == 3) {
            cin >> k; k--;
            s.trees[s.ct++] = new STP::Node(s.trees[k]->l, s.trees[k]->r);
        }
    }
}

/*

*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/
