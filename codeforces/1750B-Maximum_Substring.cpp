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
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

LL n;
char str[MX];

/*

*/

void solve() {
    LL t; cin >> t;
    while (t--) {
        cin >> n;
        LL c0 = 0;
        LL c1 = 0;
        LL con0 = 0;
        LL con1 = 0;
        LL maxcon = 0;
        for (LL i = 0; i < n; i++) {
            char c;
            cin >> c;
            str[i] = c;
            if (c == '0') {
                c0++;
                if (i > 0) {
                    if (str[i-1] == c) {
                        con0++;
                    } else {
                        con0 = 1;
                    }
                } else {
                    con0 = 1;
                }
                maxcon = max(maxcon, con0);
            } else if (c == '1') {
                c1++;
                if (i > 0) {
                    if (str[i-1] == c) {
                        con1++;
                    } else {
                        con1 = 1;
                    }
                } else {
                    con1 = 1;
                }
                maxcon = max(maxcon, con1);
            }
        }
        cout << max(c0*c1, maxcon * maxcon) << '\n';
    }
}





