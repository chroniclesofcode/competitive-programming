#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr array<int,2>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
unordered_set<int> adj[MX];
vector<int> ans;
int deg[MX];

void dfs(int u) {
    while (!adj[u].empty()) {
        auto it = adj[u].begin();
        int v = *it;
        adj[u].erase(adj[u].find(v));
        adj[v].erase(adj[v].find(u));
        dfs(v);
    }
    ans.push_back(u);
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].insert(b);
        adj[b].insert(a);
        deg[a]++; deg[b]++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] & 1) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }
    dfs(0);
    if (ans.size() != m+1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    for (auto a : ans) {
        cout << a+1 << ' ';
    }
    cout << '\n';
}

/*

*/



