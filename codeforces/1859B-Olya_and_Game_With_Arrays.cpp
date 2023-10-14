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
#define IINF (int)1e9+1
#define INF numeric_limits<LL>::max() / 2
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n;

/*

*/

void solve() {
    cin >> n;
    LL ans = 0;
    LL small = IINF;
    LL second = IINF;
    LL minbig = IINF;
    for (LL i = 0; i < n; i++) {
        LL m; cin >> m;
        vector<LL> a;
        for (LL j = 0; j < m; j++) {
            LL x; cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        small = min(small, a[0]);
        minbig = min(minbig, a[1]);
        ans += a[1];
    }

    cout << ans - minbig + small << '\n';
}
 
