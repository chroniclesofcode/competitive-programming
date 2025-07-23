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

LL n, m, k, q;


class Fenwick {
public:
    LL n;
    vector<LL> BIT;

    Fenwick() {}
    Fenwick(LL sz) : n{sz}, BIT(sz+1, 0) {}

    void add(LL x, LL add) {
        x++;
        for (; x <= n; x += x&-x) {
            BIT[x] += add;
        }
    }

    LL query(LL x) {
        x++;
        LL sum = 0;
        for (; x > 0; x -= x&-x) {
            sum += BIT[x];
        }
        return sum;
    }

    LL pref(LL st, LL end) {
        if (st > end) return 0;
        return st <= 0 ? query(end) : query(end) - query(st-1);
    }
};



void solve() {
    cin >> n;
    vector<LL> a(n);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL big = 1e7 + 1;
    Fenwick ft(big+1);
    vector<LL> ans(n);
    for (LL i = 0; i < n; i++) {
        LL val = a[i] + ft.pref(i, big) + i;
        ft.add(val, 1);
        ans[i] = max((LL)0, val - (n-1));
    }
    for (LL i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}

/*
    Every single elem will lose value equal to the number
    in front of them.
    Every single elem will gain value equal to the number
    of elems previously WHICH have a greater stone value (or equal)
    to the distance between them.
*/