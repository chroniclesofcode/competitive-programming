#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define prLL_vec(x, n) for (LL i = 0; i < n; i++) cout << x[i] << ' '; cout << endl;
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

LL n, m, k, dist[MX], dis, e;
vector<arr2> adj[MX];
LL ans = 0;

LL dp[MX][2];
LL mxval = 0;
LL mxidx = 0;
 
void dfs(LL u, LL p, LL depth) {
	for (auto &[v,w] : adj[u]) {
		if (v == p) continue;
		dfs(v, u, depth + w);
	}

	if (depth > dis) {
		dis = depth;
		e = u;
	}
}


LL calc(LL u, LL p) {
    LL ct = 0;
    for (auto &[v, w] : adj[u]) {
        if (v == p) continue;
        ct += calc(v, u) + 2*w;
    }
    return ct;
}


void solve() {
    cin >> n;
    LL a, b, c;
    LL tot = 0;
    for (LL i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        a--; b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        tot += 2 * c;
    }
    dfs(0, -1, 0);
	dis = 0;
	dfs(e, -1, 0);
    cout << tot - dis << '\n';
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
