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

LL n, m;
vector<LL> adj[MX];
LL pred[MX];
bool vis[MX];
LL group[MX];
/*

*/

LL endv = -1;
LL curr = -1;
LL flag = 0;

void dfs(LL v, LL p) {
    if (flag) return;
    //cout << "v: " << v+1 << " group[v]: " << group[v] << " curr: " << curr <<  endl;
    if (vis[v]) {
        if (group[v] == curr) {
            endv = v;
            flag = 1;
            pred[v] = p;
            return;
        } else {
            return;
        }
    }
    vis[v] = true;
    pred[v] = p;
    group[v] = curr;

    for (auto &u : adj[v]) {
        dfs(u, v);
    }
}

void solve() {
    cin >> n >> m;
    LL z1, z2;
    for (LL i = 0; i < m; i++) {
        cin >> z1 >> z2;
        adj[z1-1].push_back(z2-1);
    }

    for (LL i = 0; i < n; i++) {
        if (flag) break;
        curr = i+1;
        dfs(i, -1);
    }
    cout << "here " << endv << " pred: " << pred[endv] << endl;
    if (!flag) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    vector<LL> path;
    for (LL p = pred[endv]; p != endv; p = pred[p]) {
        path.push_back(p);
    }
    if (path.size() == 0 || !flag) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    reverse(path.begin(), path.end());
    cout << path.size()+2 << endl;
    cout << endv+1 << " ";
    for (auto &e : path) {
        cout << e+1 << " ";
    }
    cout << endv+1 << endl;
}






