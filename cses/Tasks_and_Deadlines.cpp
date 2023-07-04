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

#define arr array<LL,2>
LL n;
vector<arr> a;
/*

*/

void solve() {
    cin >> n;
    LL x, y;
    for (LL i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back({x,y});
    }
    sort(a.begin(), a.end());
    LL ans = 0;
    LL curr = 0;
    for (auto &e : a) {
        curr += e[0];
        ans += e[1] - curr; 
    }
    cout << ans << endl;
}





