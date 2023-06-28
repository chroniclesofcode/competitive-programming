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
    LL x;
    for (LL i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    if (a[0] != 1) {
        cout << 1 << endl;
        return;
    }
    LL res = 1;
    LL crs = a[0];
    for (LL i = 1; i < n; i++) {
        if (a[i] > crs+1) {
            res = crs+1;
            break;
        }
        crs += a[i];
        res = crs+1;
    }
    cout << res << endl;

}





