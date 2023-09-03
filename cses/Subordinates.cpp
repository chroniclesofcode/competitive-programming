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

const LL MX = 5 * 1e5;
//const LL MOD = 1e7;

int n, child[MX];
vector<int> adj[MX];

/*

*/

int dfs(int u) {
    int sum = 0;
    for (int v : adj[u]) {
            sum += dfs(v);
    }
    child[u] = sum;
    return 1 + sum;
}

void solve() {
    cin >> n;
    int x;
    for (int i = 1; i < n; i++) {
        cin >> x; x--;
        adj[x].push_back(i);
    }
    child[0] = dfs(0) - 1;
    for (int i = 0; i < n; i++) {
        cout << child[i] << ' ';
    }
    cout << endl;
}





