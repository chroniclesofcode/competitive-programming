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
const LL MX = 2 * 1e5 + 20;
//const LL MOD = 1e7;

LL n;
array<LL, 3> a[MX];
set<array<LL, 2>> dp;

/*
   dp = closing time, max price
*/

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0] >> a[i][2];
    }
    sort(a, a+n);
    LL maxp = 0;
    dp.insert({ 0, 0 });
    for (LL i = 0; i < n; i++) {
        auto it = dp.lower_bound({a[i][1]});
        it--;
        maxp = max(maxp, (*it)[1] + a[i][2]);
        dp.insert({ a[i][0], maxp });
    }
    cout << (*--dp.end())[1] << endl;
}



