#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 2 * 1e5;
//const LL MOD = 1e7;

LL n, q, t[4*MX];
vector<LL> a;

void build(vector<LL> &a, LL v, LL tl, LL tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        LL tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = max(t[v*2],t[v*2+1]);
    }
}

LL query(LL v, LL tl, LL tr, LL l, LL r) {
    if (l > r) 
        return -1;
    if (l == tl && r == tr) {
        return t[v];
    }
    LL tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)),
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
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
        t[v] = max(t[v*2], t[v*2+1]);
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
        LL y;
        cin >> y;
        if (y > t[1]) {
            cout << 0 << ' ';
            continue;
        }
        LL lo = 0;
        LL hi = n-1;
        while (lo <= hi) {
            // Found
            if (lo == hi) {
                cout << lo+1 << ' ';
                update(1, 0, n-1, lo, a[lo] - y);
                a[lo] -= y;
                break;
            }
            LL mid = lo + (hi-lo)/2;
            if (query(1, 0, n-1, lo, mid) >= y) {
                hi = mid;
            } else {
                lo = mid+1;
            }
        }
    }
    cout << endl;
}





