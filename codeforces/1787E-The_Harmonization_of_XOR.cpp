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

int n, m, k, x, vis[MX];

void solve() {
    cin >> n >> k >> x;
    vector<vector<int>> ans;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        if (i == x) {
            vis[i] = 1;
            ans.push_back({i}); continue;
        }
        int tmp = i^x;
        if (tmp <= n && !vis[tmp]) {
            vis[i] = 1; vis[tmp] = 1;
            ans.push_back({i,tmp}); continue;
        }
    }
    ans.push_back({});
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            tmp ^= i;
            ans.back().push_back(i);
        }
    }
    if ((tmp != x && tmp != 0) || ans.size() < k) {
        cout << "NO\n"; return;
    }
    for (int i = k; i < ans.size(); i++) {
        ans[k-1].insert(ans[k-1].end(), ans[i].begin(), ans[i].end());
    }
    tmp = 0;
    for (auto e : ans[k-1]) tmp ^= e;
    if (tmp != x) {
        cout << "NO\n"; return;
    }
    cout << "YES\n";
    for (int i = 0; i < k; i++) {
        auto &a = ans[i];
        cout << a.size() << ' ';
        for (auto e : a) cout << e << ' ';
        cout << '\n';
    }

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
