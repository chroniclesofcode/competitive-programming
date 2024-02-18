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

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 3 * 1e5+1;
constexpr LL MD = 998244353;

LL n, m, k, subt[MX], dp[MX];
long long ans = 0;
vector<LL> adj[MX];

void dfs(LL u, LL p) {
    dp[u] = 1;
    for (LL v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        dp[u] *= (dp[v]+1);
        dp[u] %= MD;
    }
}

void solve() {
    cin >> n;
    for (LL i = 0; i < n; i++) adj[i].clear();
    memset(dp, 0, sizeof(dp));
    for (LL i = 0; i < n-1; i++) {
        LL u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    LL no_anc = dp[0] + 1;
    LL has_anc = 0;
    for (LL i = 1; i < n; i++) has_anc += dp[i];
    cout << (no_anc + has_anc)%MD << '\n';
}

