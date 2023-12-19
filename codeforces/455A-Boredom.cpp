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

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = LLONG_MAX / 2;
constexpr LL MX = 3 * 1e5;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;
LL nums[MX];
LL dp[MX];

void solve() {
    cin >> n;
    LL big = 0;
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x;
        big = max(big, x);
        nums[x]++;
    }
    for (LL i = 0; i <= big; i++) {
        dp[i] = i * nums[i];
        if (i >= 1) {
            dp[i] = max(dp[i], dp[i-1]);
        }
        if (i >= 2) {
            dp[i] = max(dp[i], i*nums[i] + dp[i-2]);
        }
    }
    cout << dp[big] << '\n';
}

/*

*/



