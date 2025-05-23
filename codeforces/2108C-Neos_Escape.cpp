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

int n, m, k, q;

void solve() {
    cin >> n;
    vector<int> a;
    map<int, vector<int>, greater<int>> compress;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back(x);
        compress[x].push_back(i);
    }
    vector<int> vis(n+1, 0);
    int ans = 0;
    for (auto& [num, vec] : compress) {
        for (int i = 0; i < vec.size(); i++) {
            int idx = vec[i];
            if (vis[idx+1] || (idx-1>=0 && vis[idx-1])) {
                vis[idx] = 1;
            }
        }
        for (int i = vec.size() - 1; i >= 0; i--) {
            int idx = vec[i];
            if (vis[idx+1] || (idx-1>=0 && vis[idx-1])) {
                vis[idx] = 1;
            } else {
                ans++;
                vis[idx] = 1;
            }
        }
    }
    cout << ans << '\n';
}

/*

*/