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
constexpr int MX = 2 * 1e5 + 10;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

class SegtreePNode {
public:
    LL n = 0;
    
    struct node {
        LL x;
        node() : x{0} {}
        node(int e) : x{e} {}

        friend node operator+(const node &a, const node &b) {
            return node(max(a.x, b.x));
        }
    };

    vector<node> t;

    SegtreePNode(LL sz) : n(sz), t(4 * sz + 1) {}

    node query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return node();
        if (l == tl && r == tr) {
            return t[v];
        }
        LL tm = (tl + tr) / 2;
        return query(l, min(r, tm), v * 2, tl, tm) +
               query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr);
    }

    void update(LL pos, LL new_val, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (tl == tr) {
            t[v] = new_val;
        } else {
            LL tm = (tl + tr) / 2;
            if (pos <= tm)
                update(pos, new_val, v * 2, tl, tm);
            else
                update(pos, new_val, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    int qry(int l, int r) {
        if (r < l) return 0;
        return query(l, r).x;
    }
};

void solve() {
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> cc;
    for (int i = 0; i < n; i++) {
        cc[a[i]] = 1;
    }
    int ct = 1;
    int prev = -1e9;
    unordered_map<int, int> idx, asc;
    for (auto &e : cc) {
        if (prev == e.first-1) {
            // asc means there is an element right before
            // this value. So there is no gap even when
            // coordinate compressed
            asc[e.first] = 1;
        }
        idx[e.first] = ct++;
        prev = e.first;
    }
    SegtreePNode dp0(n+10), dp1(n+10);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int curr = idx[a[i]];

        int ret = dp0.qry(0, curr-1) + 1;
        dp0.update(curr, ret);
        // one update left, use on the last node if OK
        ans = max(ans, ret);

        // Note: we are trying to find the max value such that
        // it is POSSIBLE to add 1 using the change.
        if (asc[a[i]]) {
            ret = dp0.qry(0, curr-2) + 1;
            if (ret < i+1) ret++;
            ret = max(ret, dp1.qry(0, curr-1) + 1);
        } else {
            ret = dp0.qry(0, curr-1) + 1;
            if (a[i] > 0 && ret < i+1) ret++;
            ret = max(ret, dp1.qry(0, curr-1) + 1);
        }
        dp1.update(curr, ret);
        ans = max(ans, ret);
    }

    cout << ans << '\n';
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
