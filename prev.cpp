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
    string s;
    cin >> s;
    vector<int> pref(n), suf(n);
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') p++;
        pref[i] = p;
    }
    p = 0;
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == 'B') p++;
        suf[i] = p;
    }
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        if (pref[i] > 0 && suf[i+1] > 0) {
            ans++;
        }
    }
    cout << ans << '\n';
}





