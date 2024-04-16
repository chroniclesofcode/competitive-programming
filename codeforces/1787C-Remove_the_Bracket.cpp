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
    LL t;
    cin >> t;
    while (t--)
        solve();
}

constexpr LL INF = (LL)1e9 + 100;
constexpr LL LINF = std::numeric_limits<LL>::max() / 2;
constexpr LL NINF = -INF;
constexpr LL MX = 2 * 1e5 + 1;
constexpr LL MD = (LL)1e9 + 7;

LL n, m, k, s;

pair<LL,LL> split(LL num, LL s) {
    pair<LL,LL> ret;
    if (num > 2*s) {
        ret.first = s; ret.second = num-s;
    } else if (num == 2*s) {
        ret.first = s; ret.second = s;
    } else if (num > s) {
        ret.first = num-s; ret.second = s;
    } else {
        ret.first = 0; ret.second = num;
    }
    return ret;
}
LL dp[MX][2];
LL previ[MX][2];
void solve() {
    cin >> n >> s;
    vector<LL> a;
    for (LL i = 0; i < n; i++) {
        LL x; cin >> x;
        a.push_back(x);
    }
    LL ans = 0;
    //memset(dp, 0, sizeof(dp));
    for (LL i = 0; i < n; i++) {
        dp[i][0] = dp[i][1] = LLONG_MAX;
        if (i == 0) {
            dp[0][0] = dp[0][1] = 0;
            previ[0][0] = previ[0][1] = a[i];
        } else if (i == n-1) {
            ans = min(a[i]*previ[i-1][0]+dp[i-1][0], a[i]*previ[i-1][1]+dp[i-1][1]);
        } else {
            auto pp = split(a[i], s);
            dp[i][0] = min(dp[i][0], pp.first*previ[i-1][0] + dp[i-1][0]);
            dp[i][0] = min(dp[i][0], pp.first*previ[i-1][1] + dp[i-1][1]);
            dp[i][1] = min(dp[i][1], pp.second*previ[i-1][0] + dp[i-1][0]);
            dp[i][1] = min(dp[i][1], pp.second*previ[i-1][1] + dp[i-1][1]);
            previ[i][0] = pp.second;
            previ[i][1] = pp.first;
        }
    }
    cout << ans << '\n';
}

/*

*/







