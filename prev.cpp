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

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = LLONG_MAX / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;


void solve() {
    cin >> n;
    vector<int> deg(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        deg[u]++;
        deg[v]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            ans++;
        }
    }
    cout << ans/2 + ans%2 << '\n';
}

/*

*/







