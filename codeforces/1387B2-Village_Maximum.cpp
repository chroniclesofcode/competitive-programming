#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prt_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
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
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, sz[MX], rem[MX], arrange[MX];
vector<LL> adj[MX];

LL get_subt(LL u, LL p) {
    sz[u] = 1;
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        sz[u] += get_subt(v, u);
    }
    return sz[u];
}

LL centroid(LL u, LL p, LL tot) {
    for (LL v : adj[u]) {
        if (v == p || rem[v]) continue;
        if (sz[v] > tot/2) return centroid(v, u, tot);
    }
    return u;
}

vector<int> order;
void dfs(int u, int p) {
    order.push_back(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
}

void solve() {
    cin >> n; 
    vector<arr2> edges;
    for (LL i = 0; i < n-1; i++) {
        LL a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges.push_back({a, b});
    }
    LL c = centroid(0, -1, get_subt(0, -1));
    get_subt(c, -1);
    LL ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        ans += min(sz[edges[i][0]], sz[edges[i][1]]);
    }
    ans *= 2; // nodes going out, nodes going in.
    cout << ans << '\n';
    dfs(c, -1);
    for (int i = 0; i < order.size(); i++) {
        arrange[order[(i+n/2)%n]] = order[i];
    }

    for (int i = 0; i < n; i++) {
        cout << arrange[i]+1 << ' ';
    }
    cout << '\n';
}


