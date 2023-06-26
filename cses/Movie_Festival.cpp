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

int n;

vector<array<int, 2>> times;
/*

*/

void solve() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        times.push_back({b,a});
    }
    sort(times.begin(), times.end());
    int lastend = -1;
    int ans = 0;
    for (auto &e : times) {
        if (e[1] >= lastend) {
            ans++;
            lastend = e[0];
        }
    }
    cout << ans << endl;
}





