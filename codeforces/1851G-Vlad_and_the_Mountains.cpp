#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long
#define arr2 array<int,2>
#define arr3 array<int,3>
#define arr4 array<int,4>
#define arr5 array<int,5>

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
int heights[MX], grp[MX], sz[MX];

int Find(int x) {
    if (grp[x] == x) return x;
    return grp[x] = Find(grp[x]);
}

void Union(int x, int y) {
    x = Find(x); y = Find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    grp[y] = x;
    sz[x] += sz[y];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        grp[i] = i; sz[i] = 1;
    }
    vector<arr3> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        edges.push_back({max(heights[u],heights[v]), u, v});
    }
    int q;
    cin >> q;
    vector<arr4> queries;
    queries.reserve(q);
    for (int i = 0; i < q; i++) {
        int a, b, e;
        cin >> a >> b >> e; a--; b--;
        queries.push_back({heights[a]+e, a, b, i});
    }
    sort(queries.begin(), queries.end());
    sort(edges.begin(), edges.end());
    vector<int> ans(q);
    int j = 0;
    for (int i = 0; i < q; i++) {
        while (j < edges.size() && edges[j][0] <= queries[i][0]) {
            Union(edges[j][1], edges[j][2]);
            j++;
        }
        if (Find(queries[i][1]) == Find(queries[i][2])) {
            ans[queries[i][3]] = 1;
        }
    }
    for (int i = 0; i < q; i++) {
        if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}

/*

*/







