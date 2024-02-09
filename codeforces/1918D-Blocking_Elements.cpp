#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 1 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;

void solve() {
    LL n;
    cin >> n;
    vector<LL> a(n+1, 0);
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    LL lo = 0, hi = INF;
    LL ans = INF;
    while (lo <= hi) {
        LL mid = lo + (hi-lo)/2;
        // we want lowest value of dp (since represents an
        // index which is blocked)
        priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
        pq.push({0, 0});
        // dp[i] = lowest blocked sum if blocked at i
        vector<LL> dp(n+1, 0);
        LL run = 0;
        for (LL i = 0; i <= n; i++) {
            while (!pq.empty() && run - pq.top()[1] > mid) {
                pq.pop();
            }
            dp[i] = pq.empty() ? INF : pq.top()[0] + a[i];
            run += a[i];
            pq.push({ dp[i], run });
        }
        if (dp[n] > mid) {
            lo = mid+1;
        } else {
            hi = mid-1;
            ans = min(ans, mid);
        }
    }
    cout << ans << '\n';
}

/*
   dp[i][0/1] = if we block at i, if we don't block at i
*/







