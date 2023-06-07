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
const LL MX = 2 * 1e5 + 10;
//const LL MOD = 1e7;

LL n;
LL a[MX];
vector<LL> dp;

/*
    dp[i] is going to represent the minimum number at the
    end of the subsequence
*/

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (LL i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);    
        if (it == dp.end()) {
            dp.push_back(a[i]);
        } else {
            dp[(--it)-dp.begin()+1] = a[i];
        }
    }
    cout << dp.size() << endl;
}





