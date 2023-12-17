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
const LL MX = 5 * 1e6;
//const LL MOD = 1e7;

int n;

/*

*/

void solve() {
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
    }
    if (a.back() == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int zero = 0;
    int one = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == 1) {
            cout << 0 << ' ';
            one++;
            continue;
        }
        if (one > 0) {
            cout << one << ' ';
            one = 0;
        }
        if (i > 0 && a[i-1] == 1) {
            continue;
        }
        cout << 0 << ' ';
    }
    if (one > 0) {
        cout << one;
    }
    cout << '\n';
}





