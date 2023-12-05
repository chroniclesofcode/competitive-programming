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

#define INF numeric_limits<LL>::max() / 2
const LL MX = 1001;
//const LL MOD = 1e7;

int n, m[MX][MX], ans[MX];

/*

*/

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x; cin >> x;
            m[i][j] = x;
        }
    }
    if (n == 1) {
        cout << "YES\n1\n";
        return;
    }

    int inf = (int)1e9+1;
    for (int i = 0; i < n; i++) {
        int elem = (1 << 30) - 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int k = 0; k < 30; k++) {
                    if (!((m[i][j] >> k) & 1) && (elem >> k) & 1) {
                        elem = elem ^ (1 << k);
                    }
                }
            }
        }
        ans[i] = elem;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if ((ans[i]|ans[j]) != m[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}





