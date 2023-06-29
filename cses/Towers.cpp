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

int n, a[MX];
multiset<int> towers;
/*

*/

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    towers.insert(a[0]);
    for (int i = 1; i < n; i++) {
        auto it = towers.lower_bound(a[i]);
        if (it == towers.end()) {
            towers.insert(a[i]);
        } else if (*it == a[i]) {
            auto it2 = towers.upper_bound(a[i]);
            if (it2 == towers.end()) {
                towers.insert(a[i]);
            } else {
                towers.erase(it2);
                towers.insert(a[i]);
            }
        } else {
            towers.erase(it);
            towers.insert(a[i]);
        }
    }
    cout << towers.size() << endl;
}





