#include <bits/stdc++.h>
#include <fstream>

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
const LL MX = 5 * 1e5 ;
//const LL MOD = 1e9 + 7;

int n, k;
vector<pair<int, int>> adj[MX];
bool used[MX];
int ppl[MX];
int dep[MX];
bool vis[MX];
vector<pair<int, int>> nodes;
int ret = 0;
vector<pair<int, int>> adj1[MX];

void dfs(int u, int flo, int d) {
    //if (used[u]) continue;
    ppl[u] = flo;
    dep[u] = d;
    //used[u] = true;
    nodes.push_back({dep[u], u});
    for (auto v : adj[u]) {
        int n1 = v.first; // node
        int n2 = v.second; // maxppl
        dfs(n1, min(flo, n2), d+1);
    }
}

int dfs0(int u) {
    int mini = ppl[u];
    for (auto v : adj1[u]) {
        mini = min(mini, dfs0(v.first));
    }
    return mini;
}

void dfs1(int u, int &left) {
    ppl[u] -= left;
    for (auto v : adj1[u]) {
        dfs1(v.first, left);
    }
}
void debug() {
    cout << "START\n";
    for (int i = 0; i < n; i++) {
        cout << ppl[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << dep[i] << " ";
    }
    cout << endl;
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n-1; i++) {
        int p, c;
        cin >> p >> c;
        adj[p].push_back({i, c});
        adj1[i].push_back({p, c});
    }
    dfs(0, k, 0);
    sort(nodes.begin(), nodes.end(), greater<pair<int, int>>());
    //debug();
    int cur = k;
    for (auto p : nodes) {
        //int n1 = p.first; // depth
        int n2 = p.second; // node
        if (!used[n2] && ppl[n2] > 0 && cur > 0) {
            int rem = min(ppl[n2], cur);
            int small = min(dfs0(n2), rem);
            //cout << n2 << " VISIT\n";
            ret += dep[n2] * small;
            cur -= small;
            dfs1(n2, small);
            used[n2] = true;
        }
    }
    //debug();
    cout << ret << '\n';
}





