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

int n, x;
int a[MX];
unordered_map<int, int> m;
/*

*/

void solve() {
    m.reserve(1024);
    m.max_load_factor(0.25);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (m[x-a[i]] > 0 && i != m[x-a[i]]) {
            cout << i << " " << m[x-a[i]] << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE\n";
}





