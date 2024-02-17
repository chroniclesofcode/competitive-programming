#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = std::numeric_limits<int>::max() / 2;
constexpr int NINF = -INF;
constexpr LL MX = 3 * 1e5;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
vector<int> adj[MX];
int subt[MX];

void dfs(int u) {
    subt[u] = 1;
    for (int v : adj[u]) {
        dfs(v);
        subt[u] += subt[v];
    }
}

int calc(int u, int k) {
    int tot = 0; int big = -1;
    for (int v : adj[u]) {
        tot += subt[v];
        if (big == -1 || subt[v] > subt[big]) {
            big = v;
        }
    }
    if (tot == 0 || big == -1) return 0;
    int match = tot - subt[big];
    int to_pair = subt[big] - k;
    // the largest gets matched away, means it
    // is always possible to divide all
    if (to_pair <= match) {
        return (tot-k) / 2;
    }
    // Otherwise, all of match gets matched, but
    // there is still some remaining to_pair.
    return match + calc(big, max(0, k + match - 1));
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) adj[i].clear();
    memset(subt, 0, sizeof(subt));
    for (int i = 1; i <= n-1; i++) {
        int pi; cin >> pi; pi--;
        adj[pi].push_back(i);
    }
    dfs(0);
    cout << calc(0, 0) << '\n';
}

/*
    can only have depth of 3 (or 4 levels)
    get the timer of each element
*/







