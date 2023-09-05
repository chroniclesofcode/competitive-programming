#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
}

#define INF numeric_limits<LL>::max() / 2
#define NINF -INF

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

int n;

/*

*/

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (j == 0 || j == i-1) {
                cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
}





