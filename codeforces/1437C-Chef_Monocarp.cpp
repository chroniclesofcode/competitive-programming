#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
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
const LL MX = 5 * 1e4;
//const LL MOD = 1e7;

long long n;
vector<long long> a;

/*
2 2 4 4 4 5
*/

void solve() {
    a.clear();
    cin >> n;
    long long x;
    long long big = 0;
    for (long long i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
        big = max(big, x);
    }
    big += n;
    sort(a.begin(), a.end());

    vector<vector<long long>> dp(n+1, vector<long long>(big,INF));
    dp[0][0] = a[0];
    for (long long j = 1; j < big; j++) {
        dp[0][j] = min(dp[0][j-1], abs(j - a[0]));
    }
    for (long long i = 1; i < n; i++) {
        for (long long j = 0; j < big; j++) {
            if (j > 1) {
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(j - a[i]));
            }
        }
    }
    cout << dp[n-1][big-1] << '\n';
}





