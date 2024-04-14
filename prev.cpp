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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr int INF = (int)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr int NINF = -INF;
constexpr int MX = 1501;
constexpr int MD = (int)1e9 + 7;

int n, m, k;

vector<int> adj[MX];
int cost[MX];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) adj[i].clear();
    memset(cost, 0, sizeof(cost));
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        if (a == 0) continue;
        adj[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    int lvl = 1;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int u = q.front(); q.pop();
            if (cost[u] > 0) continue;
            cost[u] = lvl;
            for (int v : adj[u]) q.push(v);
        }
        lvl++;
    }
    vector<int> occ[n+2];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!cost[i]) {
            cout << "INFINITE\n";
            return;
        }
        occ[cost[i]].push_back(i);
        ans += cost[i];
    }
    cout << "FINITE\n";
    cout << ans << '\n';
    for (int i = n; i >= 1; i--) {
        for (int j = i; j <= n; j++) {
            for (auto k : occ[j]) {
                cout << k+1 << ' ';
            }
        }
    }
    cout << '\n';
}

/*
   the key is the 1. If the edges don't
   have a 1, infinite. If n > 1 and m == 0,
   infinite. If not every number is specified
   in the edges, you can just spam it forever
   -> infinite.

   Everything needs to 'dance'
   around the one. The second there is an edge
   associated with a 1, you can only have
   one wrap around 1. E.g. 3->1, the only possible
   combination is 313. If we do 3313, the two 3's
   won't have a 1 in between. Now, if something
   else is connected to 3, e.g. 2->3, then you can
   wrap the 2's around ONE 3, and one at the end.
   232132. So basically, you are allowed 1 more
   than the element you are connected to. 3 is 
   connected to 1 (limited to 1), so there's only
   2 3's. 2 is connected 3 which is allowed 2,
   so is allowed 3. If something is connected to 2,
   then we are allowed 4 of that.

   everything is a tree starting from 1 -> it will
   go downwards, everything will be increasing by
   1. If a number is not within this tree, then
   infinity. If 1 is on the left, then skip it. 
   
   BFS for the length.
   Then, we know that all max lengths can come
   first, then max lengths-1 -> since max lengths
   will always be attached to max lengths-1. and
   1 will always appear once only. So it goes
   n, n-1, n, n-2, n-1, n, n-3, n-2, n-1, n etc etc.

*/







