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

LL n, m, k, q;

vector<LL> nums;
vector<LL> tmp;
LL ans = 0;

void dfs(int idx, int ct, LL x) {
    if (ct == 0) {
        ans = max(ans, x);
        return;
    }
    if (n - idx < ct) return;
    for (int i = idx; i < n - ct + 1; i++) {
        dfs(i + 1, ct - 1, x ^ nums[i]);
    }
}

void solve() {
    cin >> n >> k;
    nums = vector<LL>(n);
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        nums[i] = x;
    }
    if (n - k < k) {
        LL tot = 0;
        for (int i = 0; i < n; i++) {
            tot ^= nums[i];
        }
        dfs(0, n-k, tot);
    } else {
        dfs(0, k, 0);
    }
    cout << ans << '\n';
}

/*

*/