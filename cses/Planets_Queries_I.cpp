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

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;
const LL LOG = 31;

LL n, q;
LL par[MX][LOG];

/*

*/

LL jump(LL u, LL k) {
    for (LL i = 0; i < LOG; i++) {
        if ((1 << i) & k) {
            u = par[u][i];
        }
    }
    return u;
}

void solve() {
    cin >> n >> q;
    LL a;
    for (LL i = 0; i < n; i++) {
        cin >> a;
        par[i][0] = a-1;
    }

    for (LL i = 1; i < LOG; i++) {
        for (LL j = 0; j < n; j++) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }
    LL b;

    for (LL i = 0; i < q; i++) {
        cin >> a >> b;
        cout << jump(a-1, b)+1 << '\n';
    }
}





