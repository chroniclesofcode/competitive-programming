#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int n, k;

/*

*/

void solve() {
    cin >> n >> k;
    vector<int> dp(n+1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i += k) {
        ans++;
        dp[i] = 1;
    }
    if (dp[n] != 1) cout << ans+1;
    else cout << ans;
    cout << '\n';
}





