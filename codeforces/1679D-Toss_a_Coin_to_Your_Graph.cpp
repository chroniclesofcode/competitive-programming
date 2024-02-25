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
        solve();
}

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 3;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, vis[MX], vert[MX], dist[MX], active[MX];
vector<LL> adj[MX], order;

bool hasCycle(LL u, LL mid) {
    if (vis[u]) return false;
    vis[u] = 1;
    active[u] = 1;
    for (LL v : adj[u]) {
        if (vert[v] > mid) continue;
        if (active[v] || hasCycle(v, mid)) {
            return true;
        }
    }
    active[u] = 0;
    return false;
}

void dfs(LL u, LL mid) {
    vis[u] = 1;
    for (LL v : adj[u]) {
        if (vert[v] > mid || vis[v]) continue;
        dfs(v, mid);
    }
    order.push_back(u);
}

void solve() {
    cin >> n >> m >> k;
    LL lo = LINF, hi = 0;
    for (LL i = 0; i < n; i++) {
        cin >> vert[i];
        lo = min(lo, vert[i]);
        hi = max(hi, vert[i]);
        adj[i].clear();
    }
    for (LL i = 0; i < m; i++) {
        LL u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
    }
    LL ans = LINF;
    while (lo <= hi) {
        LL mid = lo + (hi-lo)/2;
        order.clear();
        memset(vis, 0, n*sizeof(LL));
        memset(active, 0, n*sizeof(LL));
        bool flag = false;
        for (LL i = 0; i < n; i++) {
            if (!vis[i] && vert[i] <= mid && hasCycle(i, mid)) {
                flag = true; break;
            }
        }
        if (flag) {
            ans = min(ans, mid);
            hi = mid-1;
            continue;
        }
        memset(vis, 0, n*sizeof(LL));
        for (LL i = 0; i < n; i++) {
            if (!vis[i] && vert[i] <= mid) {
                dfs(i, mid);
            }
        }
        LL mlen = 0;
        memset(dist, 0, n*sizeof(LL));
        for (auto u : order) {
            for (LL v : adj[u]) {
                if (vert[v] > mid) continue;
                dist[u] = max(dist[u], dist[v]);
            }
            dist[u]++;
            mlen = max(mlen, dist[u]);
        }
        if (mlen >= k) {
            ans = min(ans, mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    cout << (ans == LINF ? -1 : ans) << '\n';
}

/*
    binary search - cannot travel on anything
    greater than mid.
*/







