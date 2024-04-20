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
constexpr int MX = 2 * 1e5 + 1;
constexpr int MD = (int)1e9 + 7;

int n, m, k;
int a[MX], vis[MX], subt[MX], valid[MX];
vector<int> adj[MX], rev[MX];

LL ans, hotpath;

void init(int u) {
    subt[u] = 1;
    valid[u] = 1;
    for (auto v : rev[u]) {
        init(v);
        subt[u] += subt[v];
    }
}

void dfs(int u, bool possible) {
    if (possible) {
        if (u == 0) return;
        // Current node cannot match any before it
        // or to any element not exiting
        ans -= subt[u] + (n - subt[0] + 1);
    } else {
        if (vis[u]) return;
        vis[u] = 1;
        // 
        ans += n + subt[0];
    }
    for (auto v : adj[u]) {
        dfs(v, possible);
    }
}

void solve() {
    cin >> n;
    adj[0].clear();
    rev[0].clear();
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        adj[i].clear();
        rev[i].clear();
    }
    memset(vis, 0, sizeof(int) * (n+1));
    memset(valid, 0, sizeof(int) * (n+1));
    memset(subt, 0, sizeof(int) * (n+1));
    ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] + i <= n && a[i] + i >= 1) {
            adj[i].push_back(a[i]+i);
            rev[a[i]+i].push_back(i);
        } else {
            adj[i].push_back(0);
            rev[0].push_back(i);
        }
    }
    init(0);
    if (valid[1]) {
        ans += (LL)n * (2 * (LL)n + 1);
        dfs(1, true);
    } else {
        dfs(1, false);
    }
    cout << ans << '\n';
}

/*
    at minimum, you can just instantly end
    the game by overflowing backwards and 
    forwards. 
    But if not, you need to move it to an
    element that will eventually escape.
    So for every element, you need to work
    out if it will eventually escape without
    going on your current square. If it needs
    to go on your current square, then jumping
    to it will fail since it will loop back up.

    So the answer is: overflows + number of elements
    in the array which escapes without touching
    the current node (i.e underneath the current
    tree it's in).

    Observation: any path that escapes will be
    linear, there is no branching. So this element
    may just be on a path of ID and length L. If you
    think about it, all the elements can jump to
    this element (if it escapes) MINUS the ones in
    front of it. That's it.

    Now, for any cycle -> there is no obvious escape.
    So instead of asking: where can I jump to, ask
    who can jump to me?

    edge case: something that starts elsewhere, but
    merges into the hotpath -> we need to find the
    merge point, and anything above it is fine.

*/







