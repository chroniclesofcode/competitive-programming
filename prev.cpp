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

LL n, m, k, q, x;
LL dp[5002][5002][3];

void solve() {
    cin >> n >> x;
    vector<arr3> a(n);
    for (LL i = 0; i < n; i++) {
        LL vit, unit, calories;
        cin >> vit >> unit >> calories;
        a[i] = { vit-1, unit, calories };
    }
    for (LL i = 0; i < n; i++) {
        for (LL j = 1; j <= x; j++) {
            LL vit = a[i][0], unit = a[i][1], cal = a[i][2];
            if (i) {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
                dp[i][j][2] = dp[i-1][j][2];
            }
            if (cal > j) continue;
            if (i) {
                dp[i][j][vit] = max(dp[i][j][vit],
                                    dp[i-1][j-cal][vit] + unit);
            } else {
                dp[i][j][vit] = unit;
            }
        }
    }
    arr2 v0 = {0, 0};
    arr2 v1 = {0, 0};
    arr2 v2 = {0, 0};
    for (LL i = 0; i < x; i++) {
        if (v0 <= v1 && v0 <= v2) {
            v0[1]++;
            v0[0] = dp[n-1][v0[1]][0];
        } else if (v1 <= v0 && v1 <= v2) {
            v1[1]++;
            v1[0] = dp[n-1][v1[1]][1];
        } else {
            v2[1]++;
            v2[0] = dp[n-1][v2[1]][2];
        }
    } 
    cout << min({v0[0], v1[0], v2[0] }) << '\n';
}

/*
    only using 0..N foods, what is the max vitamins we can
    take?

*/