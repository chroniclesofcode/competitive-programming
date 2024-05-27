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
constexpr LL LINF = LLONG_MAX / 2;
constexpr int NINF = -INF;
constexpr LL MX = 2 * 1e5;
constexpr int MD = (int)1e9 + 7;

LL n, q;
class SegtreeRange {
public:
    using LL = long long;
    LL n = 0;
    vector<LL> t, lazy;
    SegtreeRange(LL sz) : n{sz}, t(4*sz+1), lazy(4*sz+1) {}


    void push(LL v) {
        t[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        t[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
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
            return -INF;
        if (l == tl && tr == r)
            return t[v];
        push(v);
        LL tm = (tl + tr) / 2;
        return max(query(l, min(r, tm), v*2, tl, tm), 
                   query(max(l, tm+1), r, v*2+1, tm+1, tr));
    }
};

class SegtreePoint {
public:
    using LL = long long;
    LL n = 0;
    vector<LL> t;

    SegtreePoint(LL sz) : n(sz), t(4 * sz + 1) {}

    LL query(LL l, LL r, LL v = 1, LL tl = 0, LL tr = -1) {
        if (tr == -1) tr = n - 1;
        if (l > r) 
            return 0;
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
};

class SegtreePNode {
public:
    using LL = long long;
    LL n = 0;
    
    struct node {
        int x;
        node() : x{0} {}
        node(int e) : x{e} {}

        friend node operator+(const node &a, const node &b) {
            return node(a.x + b.x);
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
};

// Adding on segments, querying for maximum
void solve() {
    cin >> n;
    LL x;
    //SegtreeRange s(n);
    SegtreePNode s(n);
    for (LL i = 0; i < n; i++) {
        cin >> x;
        //s.update(i, i, x);
        s.update(i, x);
    }
    s.update(3, 69);
    cout << s.query(1, 3).x << '\n';
}

