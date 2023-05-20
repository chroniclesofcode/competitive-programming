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
const LL MX = 1e5+5;
//const LL MOD = 1e7;

LL n, w;
//LL dp[101][MX];
pair<LL, LL> a[101];
vector<LL> dp(MX, INF);
/*
Knapsack:
    
*/

void solve() {
    cin >> n >> w;
    LL tot = 0;
    for (LL i = 1; i <= n; i++) {
        LL wi, vi;
        cin >> wi >> vi;
        a[i] = { wi, vi };
        tot += vi;
    }

    /*
       DP
       ConstraLLs means we cannot iterate on
       weight. Must iterate on possible values
       Use DP to find out which values are possible
       For every item up to i, for every j value
       calculate the minimum weight required
       to achieve that certain value
    */
    dp[0] = 0;
    for (LL i = 1; i <= n; i++) {
        for (LL j = tot - a[i].second; j >= 0; j--) {
            dp[j+a[i].second] = min(dp[j+a[i].second], dp[j] + a[i].first);
        }
    }
    LL ret = 0;
    for (LL i = tot; i >= 0; i--) {
        if (dp[i] <= w) {
            ret = i;
            break;
        }
    }
    cout << ret << '\n';

}






