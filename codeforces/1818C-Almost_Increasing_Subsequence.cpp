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

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

int n, q, a[MX], dp[MX], vis[MX], elems[MX];

void solve() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // preprocess
    int run = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && i < n-1 && a[i-1] >= a[i] && a[i] >= a[i+1]) {
            vis[i] = 0;
        } else {
            vis[i] = 1;
            run++;
        }
        elems[i] = run;
    }

    // queries
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--; r--;
        int val = l == 0 ? elems[r] : elems[r] - elems[l-1];
        if (vis[l] == 0) val++;
        if (vis[r] == 0) val++;
        if (l == r && !vis[l]) val--;
        cout << val << '\n';
    }
}





