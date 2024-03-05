#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<LL,2>
#define arr3 array<LL,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 1 * 1e5 + 100;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, vis[MX], a[MX], b[MX], top[MX];

LL dfs(LL u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    return 1 + dfs(top[b[u]]);
}

void solve() {
    cin >> n;
    memset(vis, 0, sizeof(vis));
    vector<LL> odd, even;
    for (LL i = 1; i <= n; i++) {
        cin >> a[i];
        top[a[i]] = i;
    }
    for (LL i = 1; i <= n; i++) {
        cin >> b[i]; 
    }
    LL ans = 0;
    for (LL i = 1; i <= n; i++) {
        if (!vis[i]) {
            LL dep = dfs(i);
            ans += dep/2;
        }
    }

    cout << ((ans*(n-ans))<<1) << '\n';
}

/*
   
*/







