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

int n, m, k;

vector<arr2> adj[MX]; // adj must be: [node, weight]

vector<int> dijkstra(int src) {
    vector<int> vis(n, false), dist(n, INF);
    priority_queue<arr2, vector<arr2>, greater<arr2>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto fr = pq.top(); pq.pop();
        int u = fr[1], d = fr[0];
        if (vis[u]) continue;
        vis[u] = 1;
        dist[u] = d;
        for (auto &[v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                pq.push({dist[u]+w, v});
            }
        }
    }
    return dist;
}


void solve() {

}

/*

*/

/*
   Try this if you are stuck:
1) binary search on answer
2) Try solving it in reverse
3) Think of a simpler problem 
4) Think of elements which are special
   (like minimum, maximum, deepest node in tree, root)
5) Is it graph problem?
    - super node? dp? cycles?
6) sorting on something e.g. queries?
7) Parity? something special
8) is it monotonic? could you use a PQ/stack/queue?

   EDGE CASES! N = 1, 2...
   LONG LONG
*/

