#include <bits/stdc++.h>

using namespace std;

#define MAINRET(x) in##x
#define what_is(x) cout << #x << " is " << x << endl;
#define LL long long

void solve();

MAINRET(t) main(void) {
    std::cin.tie(nullptr);
    std::cin.sync_with_stdio(false);
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 1 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k;
LL mark[MX];

void solve() {
    memset(mark, 0, sizeof(mark));
    cin >> n >> m;
    vector<LL> a(n);
    vector<LL> arr;
    for (LL i = 0; i < n; i++) cin >> a[i];
    LL lft = 0, rgt = 0, ans = 0;
    for (LL i = 0; i < n; i++) {
        if (a[i] == -1) lft++; 
        else if (a[i] == -2) rgt++;
        else if (mark[a[i]] == 0) {
            mark[a[i]] = 1; 
            arr.push_back(a[i]);
            ans++;
        }
    }
    // there are no people, only lefts and rights.
    if (ans == 0) {
        ans = max(min(lft,m), min(rgt,m));
        cout << ans << '\n';
        return;
    }
    sort(arr.begin(), arr.end());
    LL sz = arr.size();

    // only use lefts and rights.......
    LL ans2 = ans;
    LL space = m - arr.size();
    ans2 += max(min(space, rgt), min(space, lft));

    // left, right middle......
    LL vis = 0, l = 0, r = 0;
    for (int i = 1; i <= m; i++) {
        if (mark[i]) vis++;
        else r++;
    }
    for (int i = 1; i <= m; i++) {
        if (mark[i]) {
            ans = max(ans, vis + min(lft, l) + min(rgt, r));
        } else {
            l++;
            r--;
        }
    }
    
    cout << max(ans, ans2) << '\n';
}

/*

*/







