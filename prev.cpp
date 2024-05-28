#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

class SegtreeRNode {
public:
    LL n = 0;

    struct node {
        LL x;
        node() : x{0} {}
        node(LL e) : x{e} {}

        friend node operator+(const node &a, const node &b) {
            return node(a.x + b.x);
        }
        node& operator+=(const node &rhs) {
            *this = *this + rhs;
            return *this;
        }
    };

    vector<node> t, lazy;
    SegtreeRNode(LL sz) : n{sz}, t(4*sz+1), lazy(4*sz+1) {}


    void push(LL v) {
        t[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        t[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = node();
    }

    void update(LL l, LL r, LL addend, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] += addend;
            lazy[v] += addend;
        } else {
            push(v);
            LL tm = (tl + tr) / 2;
            update(l, min(r, tm), addend, v*2, tl, tm);
            update(max(l, tm+1), r, addend, v*2+1, tm+1, tr);
            t[v] = max(t[v*2], t[v*2+1]);
        }
    }

    LL query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r)
            return node().x;
        if (l == tl && tr == r)
            return t[v].x;
        push(v);
        LL tm = (tl + tr) / 2;
        return max(query(l, min(r, tm), v*2, tl, tm),
                query(max(l, tm+1), r, v*2+1, tm+1, tr));
    }
};

void solve() {
    n = 11;
    SegtreeRNode s(n);
    vector<int> a = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (int i = 0; i < n; i++) s.update(i,i,a[i]);
    cout << s.query(1,4) << '\n';
    cout << s.query(5,9) << '\n';
    s.update(3,6,3);
    s.update(6,10,4);
    for (int i = 0; i < n; i++) cout << s.query(i,i) << ' '; cout << '\n';
    cout << s.query(1,4) << " ans: " << 16 << '\n';
    cout << s.query(5,9) << " ans: " << 57 << '\n';

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
