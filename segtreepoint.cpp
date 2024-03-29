#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

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

LL n, q, t[4*MX];
vector<LL> a;

void build(vector<LL> &a, LL v, LL tl, LL tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        LL tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

LL query(LL v, LL tl, LL tr, LL l, LL r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    LL tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) +
               query(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(LL v, LL tl, LL tr, LL pos, LL new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        LL tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve() {
    cin >> n >> q;
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    build(a, 1, 0, n-1);
    for (LL i = 0; i < q; i++) {
        LL a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, n-1, b-1, c);
        } else {
            cout << query(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
}

/*

*/





