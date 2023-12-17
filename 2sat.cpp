#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = LLONG_MAX / 2;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, grp[MX], ass[MX];
vector<int> adj[MX], rev[MX], scc[MX];
vector<bool> vis(MX, false);
vector<int> order, comp, rts;

void dfs1(int u) {
    vis[u] = true;
    for (auto &v : adj[u]) {
        if (!vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    vis[u] = true;
    comp.push_back(u);
    for (auto &v : rev[u]) {
        if (!vis[v]) {
            dfs2(v);
        }
    }
}

void solve() {
    cin >> n >> m;
    int a, b;
    char c, d;
    for (int i = 0; i < n; i++) {
        cin >> c >> a >> d >> b;
        a--; b--;

        // Create the graph
        bool na = c == '-';
        bool nb = d == '-';
        a = 2*a ^ na;
        b = 2*b ^ nb;
        int nega = a ^ 1;
        int negb = b ^ 1;
        adj[nega].push_back(b);
        adj[negb].push_back(a);
        rev[b].push_back(nega);
        rev[a].push_back(negb);
        // Note: c, d == pos or neg
        // (c(a) OR d(b)) AND ( ...etc )
        //adj[a].push_back(b);
        //rev[b].push_back(a);
    }

    for (int i = 0; i < m*2; i++) {
        if (!vis[i]) {
            dfs1(i);
        }
    }
    vis.assign(m*2, false);

    reverse(order.begin(), order.end());

    int j = 1;
    for (auto &v : order) {
        if (!vis[v]) {
            dfs2(v);

            int rt = comp.front();
            for (auto &u : comp) {
                grp[u] = j;
            }
            rts.push_back(rt);

            j++;
            comp.clear();
        }
    }

    for (int i = 0; i < m*2; i+=2) {
        if (grp[i] == grp[i+1]) {
            cout << "IMPOSSIBLE\n";
            return;
        }
        // If neg comes later in scc, it will be set
        // x will be set to true. i/2 = x, i is a, i+1 is neg a.
        // Below, we set i/2 to be false when grp[i] < grp[i+1]
        // so we set i/2 to be true when grp[i] > grp[i+1]
        ass[i/2] = grp[i] > grp[i+1];
    }

    for (int i = 0; i < m*2; i+=2) {
        
        if (ass[i/2]) {
            cout << '+' << ' ';
        } else {
            cout << '-' << ' ';
        }
    }
    cout << endl;

}

/*

*/




