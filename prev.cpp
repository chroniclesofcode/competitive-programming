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
const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

LL n, w;
LL a[MX][2]; 
LL dp[110][MX];
/*

*/

void solve() {
    cin >> n >> w;

    for (LL i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[i][0] = u; // weight
        a[i][1] = v; // value
    }
}





