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
    int x;
    int ans = 1;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (ans == x) {
            ans += 2;
            flag = true;
        } else {
            ans++;
            flag = false;
        }
    }
    cout << ans-1 << '\n';
}




