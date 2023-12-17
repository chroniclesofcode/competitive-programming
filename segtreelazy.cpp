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

LL n, q, t[4*MX], lazy[4*MX];
vector<LL> a;

void build(vector<LL>& a, LL v, LL tl, LL tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        LL tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

void push(LL v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(LL v, LL tl, LL tr, LL l, LL r, LL addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        LL tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

LL query(LL v, LL tl, LL tr, LL l, LL r) {
    if (l > r)
        return -INF;
    if (l == tl && tr == r)
        return t[v];
    push(v);
    LL tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

// Adding on segments, querying for maximum
void solve() {
    cin >> n >> q;
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);

    }
    build(a, 1, 0, n-1);
}

/*

*/



