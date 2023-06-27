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
#define NINF -INF

const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n;
vector<LL> a;
/*

*/

void solve() {
    cin >> n;
    LL b;
    for (LL i = 0; i < n; i++) {
        cin >> b;
        a.push_back(b);
    }
    sort(a.begin(), a.end());
    LL med = a[n/2];
    LL ans = 0;
    for (LL i = 0; i < a.size(); i++) {
        ans += abs(med - a[i]);
    }
    cout << ans << endl;
}





