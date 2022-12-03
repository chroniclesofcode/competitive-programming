#include <bits/stdc++.h>
#include <fstream>

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
const LL MX = 1e3+1;
//const LL MOD = 1e9 + 7;
const LL MOD = 1e9 + 7;
LL n, k;
LL a[MX];
LL dp[MX];
LL binom[MX][MX];

LL madd(LL a, LL b) {
    return (a + b)%MOD;
}

void precomp() {
    for (LL i = 0; i <= MX; i++) {
        binom[i][0] = 1;
        for (LL j = 1; j <= i; j++) {
            binom[i][j] = madd(binom[i-1][j-1], binom[i-1][j]);
        }
    }
}

void solve() {
    cin >> k;
    for (LL i = 0; i < k; i++) {
        cin >> a[i];
    }
    precomp();
    dp[0] = 1;
    LL sum = a[0];
    for (LL i = 1; i < k; i++) {
        sum += a[i];
        dp[i] = dp[i-1] * binom[sum-1][a[i]-1];
        dp[i] %= MOD;
        //sum %= MOD;
    }
    cout << dp[k-1] << '\n';
}



