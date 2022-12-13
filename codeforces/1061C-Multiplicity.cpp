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
const LL MX = 2 * 1e6;
const LL MOD = 1e9 + 7;

LL n;
LL a[MX];
LL dp[MX];
vector<LL> fac[MX];

/*
   dp[i][j] is equal to number of good subsq up to number n
            of length j;
   dp[i][j] += dp[i-1][j-1] IF divisible by j

   so dp[i] and its iterations = number of good subarrays of
   length i.

   originally O(n^2) for every value
   but now we do factorisations instead - you'll realise
   every factor actually gets added to dp, at the value
   of the factor (if that makes sense)
*/

void solve() {
    cin >> n;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
    }
    /*
    for (LL i = 1; i <= n; i++) {
        dp[i] = 1;
    }
    */
    for(LL i = 1; i <= 1e6; i++){
        for(LL j = 1;j <= 1e6/i; j++) {
            fac[i*j].push_back(i);
        }
    }
    dp[0] = 1;
    for (LL i = 1; i <= n; i++) {
        for (LL j = fac[a[i]].size() - 1; j >= 0; j--) {
            LL val = fac[a[i]][j];
            dp[val] += dp[val-1];
            dp[val] %= MOD;
        }
        /*
        for (LL j = i; j >= 1; j--) {
            if (a[i] % j == 0) {
                dp[j] += dp[j-1];
            } else {
                dp[j] = dp[j];
            }
            dp[j] %= MOD;
        }
        */
    }
    LL ret = 0;
    for (LL i = 1; i <= n; i++) {
        ret += dp[i];
        ret %= MOD;
    }
    cout << ret << '\n';
}





