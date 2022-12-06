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
const LL MX = 5 * 1e6 ;
//const LL MOD = 1e9 + 7;

LL n, c;
LL dp[MX];
LL store[MX];
LL a[MX];
set<pair<LL, LL>> s;

// for every mountain, every mountain in front is disregarded
// find the closest shortest mountain and set that as the value
// for all the mountains in front
// For every mountain, store the mountain they can glide to.

void solve() {
    cin >> n >> c;
    for (LL i = 0; i < n; i++) {
        LL t;
        cin >> t;
        a[i] = t;
    }
    s.insert({a[0], 0});
    for (LL i = 1; i < n; i++) {
        dp[i] = dp[i-1] + abs(a[i] - a[i-1]);
        if (s.size()) {
            auto it = s.upper_bound({a[i], -1});
            if (it != s.end()) {
                LL idx = it->second;
                dp[i] = min(dp[i], dp[idx] + c);
            }
        }
        s.insert({a[i], i});
    }
    cout << dp[n-1] << '\n';
    
}




