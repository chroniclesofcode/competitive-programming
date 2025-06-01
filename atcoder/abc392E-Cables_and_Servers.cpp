#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define print_vec(x, n) for (int i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);

        solve();
}

constexpr int INF = (int)1e9 + 100; 
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k, q;

vector<arr2> adj[MX];
int vis[MX];
int visedge[MX];
vector<vector<arr3>> groupedge;

void make_group(int u, int prev, int ufid) {
    if (vis[u]) return;
    vis[u] = 1;
    for (auto& [v, id] : adj[u]) {
        if (!vis[v]) {
            make_group(v, id, ufid);
        } else if (!visedge[id] && id != prev) {
            visedge[id] = 1;
            groupedge[ufid].push_back({u, v, id});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    int distinct = 0;
    vector<arr2> rec;
    vector<int> cand;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            groupedge.push_back({});
            make_group(i, -1, distinct);
            rec.push_back({(int)groupedge[distinct].size(), distinct});
            cand.push_back(i);
            distinct++;
        }
    }
    sort(rec.begin(), rec.end(), greater<arr2>());
    cout << distinct - 1 << '\n';
    int curr = 1;
    for (auto& [sz, grpid] : rec) {
        for (auto &[u, v, id] : groupedge[grpid]) {
            if (curr < distinct) {
                cout << id+1 << ' ' << u+1 << ' ' << cand[rec[curr++][1]]+1 << '\n';
            } else {
                break;
            }
        }
    }
}

/*

*/