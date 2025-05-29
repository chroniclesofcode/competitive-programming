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

int n, m, k, q;


void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[i] = x;
    }
    map<int, vector<arr2>> queries;
    for (int i = 0; i < q; i++) {
        int r, x; cin >> r >> x;
        queries[r-1].push_back({x, i});
    }
    vector<int> ans(q);
    vector<int> dp;
    for (int i = 0; i < n; i++) {
        int elem = a[i];
        auto it = lower_bound(dp.begin(), dp.end(), elem);
        if (it == dp.end()) {
            dp.push_back(elem);
        } else {
            *it = elem;
        }
        for (auto& [x, idx] : queries[i]) {
            ans[idx] = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

/*

*/